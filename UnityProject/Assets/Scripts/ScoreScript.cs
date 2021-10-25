using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class ScoreScript : MonoBehaviour
{
    public Text score1;
    public Text total1; 
    public static int scoreValue = 0;
    public static int totalpoints = 0;
    private float total_score;

    // Update is called once per frame
    void Update()
    {
        activate_portal.current_score = 2*scoreValue + totalpoints;
        total_score = 2 * scoreValue + totalpoints;
        score1.text = "Trash collected: " + scoreValue;
        total1.text = "Total points: " + total_score;
    }
}
