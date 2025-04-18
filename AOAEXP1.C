#include &lt;math.h&gt;
#include &lt;stdio.h&gt;
void insertionSort(int arr[], int n)
{

4 | AOA Lab, Class: SE COMP
int i, key, j;
for (i = 1; i &lt; n; i++) \
{

key = arr[i];
j = i - 1;
while (j &gt;= 0 &amp;&amp; arr[j] &gt; key)

{

arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
void printArray(int arr[], int n)
{
int i;
for (i = 0; i &lt; n; i++)
printf(&quot;%d &quot;, arr[i]);
printf(&quot;\n&quot;);
}
int main()
{
int arr[] = { 12, 11, 13, 5, 6 };
int n = sizeof(arr) / sizeof(arr[0]);
insertionSort(arr, n);
printArray(arr, n);
return 0;
}