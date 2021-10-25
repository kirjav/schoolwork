using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class ChoiceScript : MonoBehaviour
{
    public TextMeshProUGUI choiceText;
    public GameObject Choice01;
    public GameObject Choice02;
    public GameObject Animator;
    public GameObject Trigger;
    public string good_choice;
    public string bad_choice;
    public int ChoiceDone;


    IEnumerator SetAnimatorParameterWithDelay(float delay)
    {
        yield return new WaitForSeconds(delay);
        Animator.SetActive(false);
        Trigger.SetActive(false);
    }

    public void ChoiceOption1()
    {
        choiceText.text = bad_choice;
        ChoiceDone = 1;
        ScoreScript.totalpoints -= 5;
        Choice01.SetActive(false);
        Choice02.SetActive(false);
 
        StartCoroutine(SetAnimatorParameterWithDelay(3));
    }
    public void ChoiceOption2()
    {
        choiceText.text = good_choice;
        ChoiceDone = 2;
        ScoreScript.totalpoints += 5;
        Choice01.SetActive(false);
        Choice02.SetActive(false);

        StartCoroutine(SetAnimatorParameterWithDelay(5));
        
    }

}
