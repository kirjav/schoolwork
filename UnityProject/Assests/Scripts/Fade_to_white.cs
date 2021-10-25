using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class Fade_to_white : MonoBehaviour
{
    
      private bool mFaded = false;
      public float Duration = 0.4f;
      public void Fade ()
    {
        var canvGroup = GetComponent<CanvasGroup>();
        StartCoroutine(DoFade(canvGroup, canvGroup.alpha, mFaded ? 0 : 1));
        mFaded = !mFaded;
    }

    public IEnumerator DoFade (CanvasGroup canvGroup, float start, float end)
    {
        float counter = 0f;

        while (counter < Duration)
        {
            counter += Time.deltaTime;
            canvGroup.alpha = Mathf.Lerp(start, end, counter / Duration);

            yield return null;
        }
    }
        

}