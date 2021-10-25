using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public class activate_portal : MonoBehaviour
{
    public float boundsgood;
    public float boundsbad;
    public GameObject GatePortal_good;
    public GameObject GatePortal_bad;
    public static int current_score;

    public GameObject onUnlocked_good; //plays animation
    public GameObject onUnlocked_bad;
    bool isUnlocked = false;
    bool isUnlockedP = false;

    /* Use bounds in 2 different functions, that are called on the gate. 
     For example: If healthy gate bounds would be - "Door gateportal_good if totalpoints > bounds"
     And polluted gate opens if "Door GatePortal_bad endabled if totalpoints < bounds" - Ena */

    void Update()
    {
        if(current_score >= boundsgood && isUnlocked == false)
        {
            onUnlocked_good.SetActive(true);
            GatePortal_good.SetActive(true);
            print("(good) door has been unlocked");
            isUnlocked = true;
        }
    // if i put it on update it always check if conditions are met for the gate to open

        if(current_score <= boundsbad && isUnlockedP == false)
        {
            onUnlocked_bad.SetActive(true);
            GatePortal_bad.SetActive(true);
            print("(bad) door has been unlocked");
            isUnlockedP = true;
        }

        if (current_score > boundsbad && current_score < boundsgood && isUnlockedP == true)
        {
            onUnlocked_bad.SetActive(false);
            GatePortal_bad.SetActive(false);
            isUnlockedP = false;
            print("(bad) door has been permanently closed");
        }
        
    }
    
}
