#include <stdio.h>

int main() {
    int f, n, faults = 0;
    
    printf("Enter number of frames and total pages: ");
    scanf("%d %d", &f, &n);
    
    int frames[f];
    for(int i = 0; i < f; i++) frames[i] = -1;
    
    printf("Enter the %d pages: ", n);
    for(int i = 0; i < n; i++) {
        int page, hit = 0;
        scanf("%d", &page);
        
        for(int j = 0; j < f; j++) 
            if(frames[j] == page) hit = 1;
      
        if(!hit) frames[faults++ % f] = page;
        
        printf("%d -> ", page);
        for(int j = 0; j < f; j++) printf("%d ", frames[j]);
        printf(hit ? "(Hit)\n" : "(Fault)\n");
    }
    
    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", n - faults); 
    
    return 0;
}
