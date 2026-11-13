import { createContext, useRef } from "react";
import EditorJS from "@editorjs/editorjs";
import Checklist from "@editorjs/checklist" //Bug arreglado con todos los imports (revisar cone)
import Header from "@editorjs/header"
import SimpleImage from "@editorjs/simple-image"
import List from "@editorjs/list"
import Embed from "@editorjs/embed"
import Underline from "@editorjs/underline"
import Marker from "@editorjs/marker"
import ChangeCase from "editorjs-change-case"
import AlignmentBlockTune from "editorjs-text-alignment-blocktune"
import Paragraph from "@editorjs/paragraph"
import InlineCode from "@editorjs/inline-code"
import ColorPlugin from "editorjs-text-color-plugin"
import Strikethrough from "@sotaproject/strikethrough"
import Alert from "editorjs-alert"

export const EditorContext = createContext()

function EditorContextProvider(props) {
  const editorInstanceRef = useRef(null)
  const initEditor = () => {
    const editor = new EditorJS({
      holder: "editorjs",
      placeholder: "Escribe una nota!",
      tools: {
        textAlignment: {
          class: AlignmentBlockTune,
          config: {
            default: "left",
            blocks: {
              header: "center"
            }
          }
        },
        paragraph: {
          class: Paragraph,
          tunes: ["textAlignment"]
        },
        header: {
          class: Header,
          inlineToolbar: true,
          tunes: ["textAlignment"],
          config: {
            placeholder: "Introduce una cabecera",
            levels: [1, 2, 3, 4, 5],
            defaultLevel: 2,
          }
        },
        alert: {
          class: Alert,
          config: {
            defaultType: "primary",
            messagePlaceholder: "Escribe una alerta"
          }
        },
        list: {
          class: List,
          config: {
            defaultStyle: "unordered"
          }
        },
       
        image: {
          class: SimpleImage,
        },
        underline: {
          class: Underline,
        },
        embed: {
          class: Embed,
          config: {
            services: {
              youtube: true,
              codepen: true,
            }
          }
        },
        strikethrough: {
          class: Strikethrough,
        },
        Marker: {
          class: Marker,
        },
        inlineCode: {
          class: InlineCode,
        },
        changeCase: {
          class: ChangeCase,
        },
        Color: {
          class: ColorPlugin,
          config: {
            // colorCollections: [
            //   '#F19647', 
            //   '#0C2A32', 
            //   '#F230B7',       error en tiempo de ejecucion
            //   '#0F48B5', 
            //   '#1112FF', 
            //   '#CCCFF4', 
            //   '#90BCE4', 
            //   '#9F1F43', 
            //   '#76C35F', 
            //   '#00000', 
            //   '#FFFFF', 
            // ],
            defaultColor: "#FF1300",
            customPicker: true,
          
        checklist: {
            class: Checklist,
             },
          }
          
        }
        
      },
    })
    editorInstanceRef.current = editor
  }
  return (  
    <EditorContext.Provider value={{initEditor, editorInstanceRef}}>
      {props.children}
    </EditorContext.Provider>
  );
}

export default EditorContextProvider;