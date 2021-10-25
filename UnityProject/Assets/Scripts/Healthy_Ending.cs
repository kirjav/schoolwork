using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Healthy_Ending : MonoBehaviour
{
    IEnumerator Exitgamewithdelay(float delay)
    {
        yield return new WaitForSeconds(delay);
        print("coroutine successfully ran application will quit now");
        Application.Quit();
    }

    // Start is called before the first frame update
     public void thisistheend ()
        {
        print("thisistheend is running");
            StartCoroutine(Exitgamewithdelay(10));

        }

}
