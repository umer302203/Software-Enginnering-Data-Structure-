#include <iostream>
using namespace std;

/*
=======================================================================
  SHELL SORT — POORI DETAIL MEIN SAMJHAYA GAYA
=======================================================================

  YE CODE KYA KARTA HAI?
  Numbers ko chote se bade order mein lagata hai (sorting).

  HAMARA ARRAY:

    arr[0] arr[1] arr[2] arr[3] arr[4]
   +------+------+------+------+------+
   |  12  |  34  |  54  |   2  |   3  |
   +------+------+------+------+------+

  Goal: Upar wale array ko neeche wala banana hai:

    arr[0] arr[1] arr[2] arr[3] arr[4]
   +------+------+------+------+------+
   |   2  |   3  |  12  |  34  |  54  |
   +------+------+------+------+------+

=======================================================================
  PEHLE SAMJHO: INSERTION SORT KYA HOTA HAI?
=======================================================================

  Socho tumhare haath mein 5 taash ke patte hain:
  [12, 34, 54, 2, 3]

  Insertion Sort ka tarika:
    Patta uthao -> Peeche walo se compare karo -> Sahi jaga rakh do

  STEP 1: 34 uthao, 12 se compare karo
   +------+         +------+
   |  12  |  <---   |  34  |   34 > 12, sahi jaga mil gayi
   +------+         +------+
   [12, 34, 54, 2, 3]  <- koi change nahi

  STEP 2: 54 uthao, 34 se compare karo
   +------+         +------+
   |  34  |  <---   |  54  |   54 > 34, sahi jaga mil gayi
   +------+         +------+
   [12, 34, 54, 2, 3]  <- koi change nahi

  STEP 3: 2 uthao, 54 se compare karo
   +------+         +------+
   |  54  |  <---   |   2  |   2 < 54, peeche jao!
   +------+         +------+
   +------+         +------+
   |  34  |  <---   |   2  |   2 < 34, peeche jao!
   +------+         +------+
   +------+         +------+
   |  12  |  <---   |   2  |   2 < 12, peeche jao!
   +------+         +------+
   [2, 12, 34, 54, 3]  <- 3 steps lage sirf 2 ke liye!

  PROBLEM:
    Chhota number agar end mein ho to use shuruaat tak aane
    mein BAHUT zyada steps lagte hain. Bade array mein ye
    bahut slow ho jata hai!

=======================================================================
  AB SAMJHO: SHELL SORT KAISE BETTER HAI?
=======================================================================

  Shell Sort ka Idea:
    "Pehle door walon ko sort karo, phir paas walon ko"

  ROUND 1 — GAP = 2 (door walon ko sort karo):

    arr[0] arr[1] arr[2] arr[3] arr[4]
   +------+------+------+------+------+
   |  12  |  34  |  54  |   2  |   3  |
   +------+------+------+------+------+
      |              |
      +----gap=2-----+    <- index 0 aur index 2 compare honge
             |              |
             +----gap=2-----+    <- index 1 aur index 3 compare honge
                    |              |
                    +----gap=2-----+    <- index 2 aur index 4 compare honge

  ROUND 2 — GAP = 1 (paas walon ko sort karo):

    Ye wohi Insertion Sort hai, LEKIN ab array thoda
    sorted hai, isliye bahut kam steps lagte hain = FAST!

=======================================================================
*/


/*
=======================================================================
  PRINT FUNCTION — ARRAY SCREEN PAR DIKHAO
=======================================================================

  Ye sirf ek kaam karta hai: array ke numbers print karo

  INPUT:
    arr[] = jo array print karna hai
    n     = kitne numbers hain array mein

  KAISE KAAM KARTA HAI:

    Maan lo arr = [12, 34, 54, 2, 3]  aur  n = 5

    Loop chalta hai:
      i=0: cout << arr[0] << " "   ->  "12 "  print hua
      i=1: cout << arr[1] << " "   ->  "34 "  print hua
      i=2: cout << arr[2] << " "   ->  "54 "  print hua
      i=3: cout << arr[3] << " "   ->   "2 "  print hua
      i=4: cout << arr[4] << " "   ->   "3 "  print hua

    Aakhir mein endl se nai line:
      Output: 12 34 54 2 3

=======================================================================
*/
void print_Array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


/*
=======================================================================
  SHELL SORT FUNCTION — YE ASLI SORTING KARTA HAI
=======================================================================

  INPUT:
    arr[] = jo array sort karna hai
    n     = kitne numbers hain

  HAMARA ARRAY SHURU MEIN:

    arr[0] arr[1] arr[2] arr[3] arr[4]
   +------+------+------+------+------+
   |  12  |  34  |  54  |   2  |   3  |
   +------+------+------+------+------+

  HAMARA ARRAY SORT HONE KE BAAD:

    arr[0] arr[1] arr[2] arr[3] arr[4]
   +------+------+------+------+------+
   |   2  |   3  |  12  |  34  |  54  |
   +------+------+------+------+------+

=======================================================================
*/
void shell_sort(int arr[], int n)
{

    /*
    -------------------------------------------------------------------
    LOOP 1 — GAP LOOP
    -------------------------------------------------------------------

    Ye loop decide karta hai: is round mein gap kitna hoga?

    Gap matlab: kitne numbers ka fark rakh ke compare karo

    N = 5 hai, to gap aise chalega:

      +-------+----------+-----------------------------------+
      | Round |   Gap    |  Kya hoga?                        |
      +-------+----------+-----------------------------------+
      |   1   | 5/2 = 2  |  2 ke gap se compare karo        |
      |   2   | 2/2 = 1  |  1 ke gap se compare karo        |
      |   3   | 1/2 = 0  |  0 ho gaya -> LOOP BAND!         |
      +-------+----------+-----------------------------------+

    KYUN gap > 0 likhte hain?
      Jab gap = 0 ho jaye to loop apne aap band ho jata hai.
      gap = 0 matlab sab sort ho gaya.

    KYUN gap /= 2 likhte hain?
      Har round mein gap aadha karte hain:
      2 -> 1 -> 0 (band)

    KYUN gap-- nahi likhte?
      gap-- matlab: 2 -> 1 -> 0 (band)
      Ye bhi kaam karta hai LEKIN /=2 zyada fast hai.
      Bade array mein gap-- se bahut zyada rounds hote hain.

    KYUN gap++ kabhi nahi?
      gap++ matlab: 2 -> 3 -> 4 -> 5 -> 6 ...
      Gap barhta rahega, loop KABHI band nahi hoga!
      Program hang ho jayega!

    -------------------------------------------------------------------
    */
    for (int gap = n/2; gap > 0; gap /= 2)
    {

        /*
        ---------------------------------------------------------------
        LOOP 2 — SELECTOR LOOP
        ---------------------------------------------------------------

        Ye loop ek ek element uthata hai jo sort hona hai.

        GAP = 2 KA EXAMPLE:

          selector = 2 (pehla uthaya gaya element):

            arr[0] arr[1] arr[2] arr[3] arr[4]
           +------+------+------+------+------+
           |  12  |  34  |  54  |   2  |   3  |
           +------+------+------+------+------+
              ^              ^
              |    gap = 2   |
              +--------------+
            ye dono compare honge

          selector = 3:

            arr[0] arr[1] arr[2] arr[3] arr[4]
           +------+------+------+------+------+
           |  12  |  34  |  54  |   2  |   3  |
           +------+------+------+------+------+
                     ^              ^
                     |    gap = 2   |
                     +--------------+
                   ye dono compare honge

          selector = 4:

            arr[0] arr[1] arr[2] arr[3] arr[4]
           +------+------+------+------+------+
           |  12  |  34  |  54  |   2  |   3  |
           +------+------+------+------+------+
                             ^              ^
                             |    gap = 2   |
                             +--------------+
                           ye dono compare honge

        KYUN selector = gap se shuru hota hai?
          Gap = 2 hai to pehla pair index 0 aur index 2 ka hai.
          Index 2 wala element pehla hai jo uthana hai.
          Isliye selector = 2 = gap se shuru karte hain.

        KYUN selector < n tak?
          n = 5 hai, indices 0 se 4 tak hain.
          selector = 4 tak jayega (last element tak).

        KYUN selector++ hota hai?
          Ek ek aage badhte hain — 2, 3, 4
          Har element ki baari aati hai sort hone ki.

        ---------------------------------------------------------------
        */
        for (int selector = gap; selector < n; selector++)
        {

            /*
            -----------------------------------------------------------
            TEMP MEIN SAVE KARO — ELEMENT UTHAO
            -----------------------------------------------------------

            Jo element uthaya hai use pehle temp mein rakh do.

            KYUN temp mein rakhte hain?

              Maan lo selector = 3, arr[3] = 2

              Uthane se pehle:
                arr[0] arr[1] arr[2] arr[3] arr[4]
               +------+------+------+------+------+
               |  12  |  34  |  54  |   2  |   3  |
               +------+------+------+------+------+
                                        ^
                                      UTHAYA!
                                      temp = 2

              Ab jab hum arr[3] mein koi aur number daalenge
              (shift karte waqt), to 2 kho jaata — isliye
              temp mein save kiya!

              temp = 2  <-- ye hamesha yaad rahega

            -----------------------------------------------------------
            */
            int temp = arr[selector];
            int searcher;

            /*
            -----------------------------------------------------------
            LOOP 3 — SEARCHER LOOP
            -----------------------------------------------------------

            Ye loop temp ke liye sahi jaga dhundta hai.
            Peeche jaata hai gap ki steps se.

            POORA EXAMPLE — step by step:

              Array shuru mein:
                arr[0] arr[1] arr[2] arr[3] arr[4]
               +------+------+------+------+------+
               |  12  |  34  |  54  |   2  |   3  |
               +------+------+------+------+------+

              selector = 3, temp = 2, gap = 2
              searcher = 3 se shuru (selector ke barabar)

            ---- CONDITION CHECK KARO ----

              DO SHARAIT HAIN (DONO SAATH SAATH POORI HONI CHAHIYE):

              SHARAT 1:  searcher >= gap
              (Safety check — negative index se bachao)

                searcher = 3, gap = 2
                3 >= 2  ->  HAAN, aage badho

                Ye check kyun zaroori hai?

                  Agar ye check na hota:
                  searcher = 1, gap = 2
                  arr[searcher - gap] = arr[1 - 2] = arr[-1]
                                                          ^
                                                   CRASH! ERROR!
                  Array mein -1 number ka index hota hi nahi!

                  Is check ki wajah se:
                  searcher = 1, gap = 2
                  1 >= 2  ->  NAHI -> loop band! Safe!

              SHARAT 2:  arr[searcher - gap] > temp
              (Kya peeche wala bada hai? Agar haan to shift karo)

                searcher = 3, gap = 2, temp = 2

                arr[searcher - gap]
                = arr[3 - 2]
                = arr[1]
                = 34

                Kya 34 > 2?  HAAN! -> Shift karo

            ---- SHIFT KARO ----

              arr[searcher] = arr[searcher - gap]
              arr[3]        = arr[3 - 2]
              arr[3]        = arr[1]
              arr[3]        = 34

              Pehle:                        Baad mein:
               arr[0] arr[1] arr[2] arr[3]   arr[0] arr[1] arr[2] arr[3]
              +------+------+------+------+  +------+------+------+------+
              |  12  |  34  |  54  |   2  |  |  12  |  34  |  54  |  34  |
              +------+------+------+------+  +------+------+------+------+
                        ^              ^                ^         ^
                      arr[1]         arr[3]           arr[1]    arr[3]
                       34              2               34    34 aa gaya!
                                       ^
                                    temp = 2 (safe hai!)

            ---- SEARCHER PEECHE JATA HAI ----

              searcher -= gap
              searcher = 3 - 2 = 1

            ---- PHIR CONDITION CHECK ----

              SHARAT 1: searcher >= gap
              1 >= 2  ->  NAHI! -> LOOP BAND!

              Loop band hua kyunki:
              searcher = 1, gap = 2
              1 - 2 = -1  <- negative index crash karta
              Isliye PEHLE hi rok diya!

            -----------------------------------------------------------
            */
            for (searcher = selector;
                 searcher >= gap && arr[searcher - gap] > temp;
                 searcher -= gap)
            {
                /*
                ---------------------------------------------------
                ANDAR KI LINE — ELEMENT SHIFT KARO
                ---------------------------------------------------

                arr[searcher] = arr[searcher - gap]

                Matlab: jo gap ki door peeche hai use
                aage la do (temp ki jagah banao)

                STEP BY STEP CALCULATION:

                  gap = 2, searcher = 3

                  arr[searcher - gap]
                  = arr[   3    -  2]
                  = arr[1]
                  = 34

                  arr[searcher] = 34
                  arr[3]        = 34

                  Pehle:                        Baad mein:
                   [0]  [1]  [2]  [3]  [4]       [0]  [1]  [2]  [3]  [4]
                  +----+----+----+----+----+     +----+----+----+----+----+
                  | 12 | 34 | 54 |  2 |  3 |     | 12 | 34 | 54 | 34 |  3 |
                  +----+----+----+----+----+     +----+----+----+----+----+
                             ^         ^                    ^         ^
                           arr[1]    arr[3]              arr[1]   arr[3]
                            34         2                  34   34 aa gaya
                                       ^
                                  temp=2 safe!

                ---------------------------------------------------
                */
                arr[searcher] = arr[searcher - gap];
            }

            /*
            -----------------------------------------------------------
            LOOP KE BAHAR — TEMP APNI JAGA PAR RAKHO
            -----------------------------------------------------------

            arr[searcher] = temp

            Ab searcher us jaga par ruka hai jahan temp ko
            rakhna hai.

            EXAMPLE:

              temp = 2, searcher = 1

              Pehle:
               arr[0] arr[1] arr[2] arr[3] arr[4]
              +------+------+------+------+------+
              |  12  |  34  |  54  |  34  |   3  |
              +------+------+------+------+------+
                        ^
                      searcher = 1
                      Yahan temp rakhna hai

              arr[searcher] = temp
              arr[1]        = 2

              Baad mein:
               arr[0] arr[1] arr[2] arr[3] arr[4]
              +------+------+------+------+------+
              |  12  |   2  |  54  |  34  |   3  |
              +------+------+------+------+------+
                        ^
                        2 apni sahi jaga par aa gaya!

            KYUN LOOP KE BAHAR HAI YE LINE?

              Andar hoti to har shift ke baad temp rakh deta:

              GALAT hota agar andar hota:
                Shift 1: arr[3] = 34   phir arr[3] = 2 rakh diya  <- GALAT!
                                        Abhi shift poori nahi hui!

              Bahar hai isliye:
                Shift 1: arr[3] = 34   (pehle jagah banao)
                Loop khatam
                PHIR: arr[1] = 2       (ab sahi jaga par rakh do)
                                        SAHI!

            -----------------------------------------------------------
            */
            arr[searcher] = temp;
        }
    }
}


/*
=======================================================================
  MAIN FUNCTION — PROGRAM YAHAN SE SHURU HOTA HAI
=======================================================================
*/
int main()
{
    int arr[] = {12, 34, 54, 2, 3};

    /*
    -------------------------------------------------------------------
    SIZEOF TRICK — ARRAY KE ELEMENTS KHUD GINAO
    -------------------------------------------------------------------

    Memory mein array aisi dikhti hai:

      arr[0]  arr[1]  arr[2]  arr[3]  arr[4]
     +-------+-------+-------+-------+-------+
     |  12   |  34   |  54   |   2   |   3   |
     +-------+-------+-------+-------+-------+
      4 bytes 4 bytes 4 bytes 4 bytes 4 bytes
     |<-------------- 20 bytes -------------->|

    CALCULATION:

      sizeof(arr)    = 20 bytes  (pura array ki memory)
      sizeof(arr[0]) =  4 bytes  (sirf ek number ki memory)

      n = sizeof(arr) / sizeof(arr[0])
      n =     20      /       4
      n =      5    <- 5 elements hain array mein!

    FAIDA KYUN?

      Agar array badlao:
        int arr[] = {12, 34, 54, 2, 3, 99, 7};  <- 7 numbers
        n = 28 / 4 = 7  (khud calculate ho gaya!)

      Haath se 7 likhna nahi pada!

    -------------------------------------------------------------------
    */
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before Sorting: ";
    print_Array(arr, n);

    shell_sort(arr, n);

    cout << "Array after Sorting:  ";
    print_Array(arr, n);

    return 0;
}
