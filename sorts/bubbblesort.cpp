// // #include <iostream>

// // // 
// //  int main(){
// //     int n;
// //     printf("Informe um número");
// //     scanf("%d",&n);
// //     int vetor[n];

  
// //     for(int i=0;i<n;i++){
// //         vetor[i]=rand()%15;

// //     }

// //       for(int i=0;i<n;i++){
// //         printf("-%d-",vetor[i]);
// //      }
// //  printf("\n");

// //     for(int i=0;i<n;i++){
// //         // printf("entrou\n");
// //         for ( int j= 0; j< n-1; j++)
// //         {if(vetor[j]>vetor[j+1]){
// //             int aux=vetor[j];
// //             vetor[j]=vetor[j+1];
// //             vetor[j+1]=aux;
// //         }
        
// //         }
        

// //     }
// //      for(int i=0;i<n;i++){
// //         printf("-%d-",vetor[i]);
// //      }
// //  }

// // #include <iostream>

// // #include <chrono>



// // int main() {
// // auto start = std::chrono::high_resolution_clock::now();
// //     int n;
// //     std::cout << "Informe um número: ";
// //     std::cin >> n;
// //     int vetor[n];

// //     for(int i=0; i<n; i++){
// //         vetor[i] = rand() % 15;
// //     }

// //     for(int i=0; i<n; i++){
// //         std::cout << "-" << vetor[i] << "-";
// //     }
// //     std::cout << "\\n";

// //     for(int i=0; i<n-1; i++){
// //         for(int j=0; j<n-i-1; j++){
// //             if(vetor[j] > vetor[j+1]){
// //                 std::swap(vetor[j], vetor[j+1]);
// //             }
// //         }
// //     }

// //     for(int i=0; i<n; i++){
// //         std::cout << "-" << vetor[i] << "-";
// //     }
// //     std::cout << std::endl;


// //     auto stop = std::chrono::high_resolution_clock::now();
// // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
// // std::cout << "Tempo de execução: " << duration.count() << " microssegundos" << std::endl;
// //     return 0;
// // }


// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <sys/time.h>

// int main() {
//   int n;
//   printf("Informe um número: ");
//   scanf("%d", &n);
//   int vetor[n];

//   for(int i = 0; i < n; i++) {
//     vetor[i] = rand() % 15;
//   }

//   for(int i = 0; i < n; i++) {
//     printf("-%d-", vetor[i]);
//   }

//   printf("\\n");

//   struct timeval inicio, fim;
//   gettimeofday(&inicio, NULL);

//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n - 1; j++) {
//       if(vetor[j] > vetor[j + 1]) {
//         int aux = vetor[j];
//         vetor[j] = vetor[j + 1];
//         vetor[j + 1] = aux;
//       }
//     }
//   }
//   printf("\n");

//   gettimeofday(&fim, NULL);
//   double tempo = (double)(fim.tv_sec - inicio.tv_sec) + (double)(fim.tv_usec - inicio.tv_usec) / 1000000.0;

//   printf("Tempo de execução: %lf segundos\\n", tempo);

// printf("\n");
//   for(int i = 0; i < n; i++) {
//     printf("%d-", vetor[i]);
//   }

//   return 0;
// }

