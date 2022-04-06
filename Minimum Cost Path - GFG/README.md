# Minimum Cost Path
## Hard 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a square <strong>grid </strong>of size <strong>N</strong>, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.<br>
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Note:&nbsp;</strong>It is assumed that negative cost cycles do not exist in the input matrix.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>grid = {{9,4,9,9},{6,7,6,4},
{8,3,3,7},{7,4,9,10}}
<strong>Output: </strong>43
<strong>Explanation: </strong>The grid is-
<span style="color:#FF0000">9 4 </span>9 9
6 <span style="color:#FF0000">7 </span>6 4
8 <span style="color:#FF0000">3 3 7</span>
7 4 9 <span style="color:#FF0000">10</span>
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>grid = {{4,4},{3,7}}
<strong>Output: </strong>14
<strong>Explanation: </strong>The grid is-
<span style="color:#FF0000">4 </span>4
<span style="color:#FF0000">3 7
</span>The minimum cost is- 4 + 3 + 7 = 14.</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anything. Your task is to complete the function&nbsp;<strong>minimumCostPath()&nbsp;</strong>which takes grid as input parameter and returns the minimum cost to react at bottom right&nbsp;cell&nbsp;from top left cell.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Compelxity:&nbsp;</strong>O(n<sup>2</sup>*log(n))<br>
<strong>Expected Auxiliary Space: </strong>O(n<sup>2</sup>)&nbsp;</span><br>
&nbsp;</p>

<p><strong><span style="font-size:18px">Constraints:</span></strong><br>
<span style="font-size:18px">1 ≤ n ≤ 500<br>
1 ≤ cost of cells ≤ 1000</span></p>
 <p></p>
            </div>