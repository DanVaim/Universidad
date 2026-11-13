using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour {

    public static SoundManager instance = null;         
    public AudioSource soundSource;
    public AudioSource musicSource;

    void Awake () {
      
        if (instance == null)
        {
            instance = this;
        }
        else if (instance != this)
        {
            DestroyObject(gameObject);
        }
    }

    public void PlaySound(AudioClip sound)
    {
            
            soundSource.PlayOneShot(sound);       
    }

    public void SwitchMusic(AudioClip music, bool loop)
    {
        if(musicSource.clip != music)
        {
            musicSource.clip = music;
            musicSource.loop = loop;
            musicSource.Play();
        }
       
    }

}
