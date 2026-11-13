using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GlobalVariables : MonoBehaviour {

    public static int playerLives = 3;
    public static bool isBig;
    public static bool hasFire;
    void Awake () {
        DontDestroyOnLoad(gameObject);
	}
	
}
