#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helper_functions.h"

/*
    SELECTION SORT ALGORITHM

    In selection sort algorithm we select the smallest element and swap it with first element for 
    respective iterations.

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/
void selection_sort(int *arr, int len) {
    for (int i=0; i < len; i++){
        
        int min_index = i; // Index of the minimum element

        for (int j = i+1; j < len; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        swap(arr, i, min_index);
    }
    return;
}

int arr_100[] = {999, 998, 1, 2,3,997,4,996,995,5,994,6,993,992,991,990,7,989,988,987,8,9,986,10,985,984,983,11,982,981,980,12,979,978,13,977,14,976,15,16,17,975,18,974,19,973,972,20,21,971,22,970,969,968,23,24,967,25,966,965,26,964,963,962,961,960,959,958,27,957,28,956,955,954,29,30,953,31,952,32,951,950,33,34,949,35,36,948,37,38,947,39,946,945,40,41,42,944,43,44,943,942,45,941,940,46,939,47,938,937,48,49,50,936,935,51,934,933,52,53,932,931,930,54,929,55,56,57,928,58,927,59,60,61,62,63,926,64,65,66,925,67,68,924,923,922,69,70,71,72,73,921,920,74,75,919,918,76,77,78,917,79,916,915,80,914,913,912,911,910,81,909,82,83,84,85,908,907,906,905,904,86,903,87,88,89,902,90,91,901,92,900,899,93,94,898,897,896,95,96,895,97,894,893,98,892,99,891,890,889,100,101,102,103,888,104,105,887,886,885,106,107,108,109,884,883,882,881,880,879,110,878,111,112,877,113,876,875,114,115,874,116,873,872,871,870,869,868,867,117,118,119,866,120,121,122,865,123,864,863,124,125,126,127,128,862,129,861,860,130,859,858,131,857,856,855,132,854,853,852,133,851,850,849,134,135,136,848,137,138,847,139,140,141,142,846,845,844,843,143,144,842,841,145,840,146,147,148,839,149,838,837,150,836,835,151,834,833,152,832,153,831,830,829,154,155,828,156,157,158,159,160,827,826,161,162,825,824,823,163,164,165,822,166,821,167,820,819,168,169,818,817,816,170,815,814,813,171,812,172,173,174,175,176,177,811,178,810,179,180,809,181,808,182,183,807,184,806,185,186,187,188,189,805,190,191,192,193,194,804,195,803,802,196,197,801,198,199,200,201,202,203,800,204,799,205,206,207,208,209,798,210,797,211,796,212,795,213,794,214,793,215,216,217,218,792,791,790,789,219,220,221,222,223,224,788,225,787,786,785,784,783,782,781,780,779,778,777,776,226,227,228,775,774,229,773,772,771,230,770,769,768,231,232,233,767,234,766,765,235,764,236,237,238,239,763,240,762,241,761,760,242,759,758,243,244,757,245,246,756,755,247,754,753,248,752,751,750,249,749,250,748,747,746,745,744,743,742,251,252,253,741,254,255,740,256,739,257,258,738,737,259,260,261,736,262,263,735,264,265,734,266,267,268,733,269,270,271,732,731,272,730,729,728,727,726,725,273,274,275,724,723,722,276,721,277,278,720,279,280,281,282,719,283,284,285,718,286,287,288,717,289,290,291,292,716,715,293,294,295,714,713,712,296,297,298,299,711,710,709,708,707,300,706,301,705,302,704,303,703,304,702,305,701,306,307,700,699,698,308,697,696,309,695,694,693,310,692,311,312,691,313,690,314,689,315,316,317,318,319,688,320,687,686,685,684,321,683,682,681,680,322,679,323,678,324,677,676,675,674,673,672,671,670,325,326,327,669,328,668,667,329,666,665,664,330,663,331,662,332,661,333,660,659,334,335,336,658,337,338,657,339,656,655,654,653,340,652,651,341,650,649,648,647,646,342,343,645,644,344,643,642,345,346,641,640,347,348,639,349,350,638,637,636,635,351,352,634,633,632,631,353,354,630,629,355,628,356,357,358,359,360,627,361,362,626,363,364,365,625,366,367,624,368,369,623,622,621,370,620,371,372,619,373,374,618,375,376,377,378,379,380,617,616,615,381,382,614,613,612,611,610,609,383,384,608,385,386,607,606,387,605,388,604,603,602,389,601,390,600,391,599,598,597,392,596,393,394,595,594,593,592,395,396,397,398,399,591,400,401,590,589,402,403,404,588,405,406,587,586,407,408,585,409,584,410,411,583,412,413,582,581,580,579,414,578,577,576,415,575,574,416,417,418,419,573,420,421,572,422,571,570,569,423,568,424,425,567,426,427,428,566,429,565,430,431,564,563,432,562,433,434,435,436,437,438,561,439,440,560,441,559,558,442,557,556,443,444,555,554,553,445,446,552,551,550,549,447,548,448,449,450,547,546,451,452,545,453,544,454,543,542,455,456,541,457,458,540,459,460,461,462,463,539,464,538,465,537,536,535,534,466,533,467,532,468,531,469,530,529,470,528,471,472,473,527,474,526,525,475,524,523,522,476,477,521,520,519,518,478,479,480,517,516,481,482,515,514,513,483,484,485,512,486,511,510,487,509,508,488,489,490,507,491,492,493,494,506,505,504,503,495,496,497,502,501,498,500,499,500};


int main() {
    int len = sizeof(arr_100) / sizeof(int);
    clock_t start, end;

    start = clock();
    selection_sort(arr_100, len);
    end = clock();

    double time_ms = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %.2lf ms\n", len, time_ms);
    return 0;
}
