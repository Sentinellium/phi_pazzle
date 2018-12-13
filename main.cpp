#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<vector<int>>> matrix(13);
    for(int i=0;i<13;i++){
        matrix[i].resize(9);
    }
    for(int i=0;i<13;i++){
        for(int j=0;j<9;j++){
        matrix[i][j].resize(3);
            for(int k=0;k<3;k++){
                matrix[i][j][k]=0;

            }
        }
    }
    /*
    matrix[0][0][0]=4;
    matrix[0][5][0]=4;
    matrix[0][8][0]=1;
    matrix[0][18][0]=1;
    matrix[0][20][0]=4;
    matrix[0][29][0]=5;

    matrix[1][6][0]=5;
    matrix[1][20][0]=11;
    matrix[1][21][0]=2;
    matrix[1][28][0]=5;

    matrix[2][2][0]=3;
    matrix[0][8][0]=6;
    matrix[0][9][0]=5;
    matrix[0][19][0]=4;
    matrix[0][21][0]=2;
    matrix[0][28][0]=7;

    matrix[0][0][0]=4;
    matrix[0][2][0]=7;
    matrix[0][10][0]=6;
    matrix[0][22][0]=6;
    matrix[0][28][0]=4;

    matrix[4][1][0]=3;
    matrix[0][13][0]=7;
    matrix[0][14][0]=5;
    matrix[0][18][0]=5;
    matrix[0][22][0]=5;

    matrix[5][3][0]=9;
    matrix[0][20][0]=4;
    */

    matrix[0][4][0]=4;
    matrix[0][7][0]=4;
    matrix[1][8][0]=5;
    matrix[2][5][0]=5;
    matrix[2][6][0]=7;
    matrix[2][8][0]=8;
    matrix[3][8][0]=8;
    matrix[5][5][0]=8;
    matrix[6][7][0]=6;
    matrix[6][8][0]=6;
    matrix[7][4][0]=5;
    matrix[8][3][0]=7;
    matrix[8][6][0]=7;
    matrix[9][2][0]=4;
    matrix[9][6][0]=4;
    matrix[10][0][0]=2;
    matrix[10][1][0]=2;
    matrix[10][6][0]=4;
    matrix[11][1][0]=1;
    matrix[11][4][0]=5;
    matrix[11][6][0]=8;
    matrix[12][2][0]=4;
    matrix[12][5][0]=7;

    matrix[0][4][1]=4; //matrix[*][*][n] where n=0 is for start points n=1 drawn points n=2 is a mark to completed ways
    matrix[0][7][1]=4;
    matrix[1][8][1]=5;
    matrix[2][5][1]=5;
    matrix[2][6][1]=7;
    matrix[2][8][1]=8;
    matrix[3][8][1]=8;
    matrix[5][5][1]=8;
    matrix[6][7][1]=6;
    matrix[6][8][1]=6;
    matrix[7][4][1]=5;
    matrix[8][3][1]=7;
    matrix[8][6][1]=7;
    matrix[9][2][1]=4;
    matrix[9][6][1]=4;
    matrix[10][0][1]=2;
    matrix[10][1][1]=2;
    matrix[10][6][1]=4;
    matrix[11][1][1]=1;
    matrix[11][4][1]=5;
    matrix[11][6][1]=8;
    matrix[12][2][1]=4;
    matrix[12][5][1]=7;

    for(int i=12;i>=0;i--){
        for(int j=0;j<9;j++){
            cout <<matrix[i][j][0];
        }
        cout <<endl;
    }

    cout <<endl;
    for(int i=0;i<13;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j][0]>0){
                if((i+matrix[i][j][0]-1<13) && (matrix[i][j][0]==matrix[i-1+matrix[i][j][0]][j][0])){
                        for(int k=i;k<i-1+matrix[i][j][0];k++){
                            matrix[k][j][1]=matrix[i][j][0];
                        }
                        matrix[i][j][2] = 1;
                        }
                if((j+matrix[i][j][0]-1<9) && (matrix[i][j][0]==matrix[i][j-1+matrix[i][j][0]][0])){
                        for(int k=j;k<j-1+matrix[i][j][0];k++){
                            matrix[i][k][1]=matrix[i][j][0];
                        }
                        matrix[i][j][2] = 1;
                        }

            }
        }
    }
    for(int i=12;i>=0;i--){
        for(int j=0;j<9;j++){
            cout <<matrix[i][j][1];
        }
        cout <<endl;
    }
    int i,j,k,maxh,maxl,maxr=0;
    while(k == 0){
        if((matrix[i][j][0] != 0) && (matrix[i][j][2] = 0)){
            if(j + matrix[i][j][0] - 1 > 8){
                maxr = 8;
            }
            else{
                maxr = j + matrix[i][j][0] - 1;
            }

            if(j - matrix[i][j][0] + 1 < 0){
                maxl = 0;
            }
            else{maxr = j - matrix[i][j][0] + 1;}

            if(i + matrix[i][j][0] - 1 > 12){
            maxh = 12;
            }
            else{maxh = i + matrix[i][j][0] - 1;}

            for(int par1=maxl; par1<=maxr;par1++){
                for(int par2=i; par2<=maxh;par1++){
                    if((matrix[par2][par1][2] == 0) && (matrix[par2][par1][0] == matrix[i][j][0])){
                        vector<vector<int>> path(i+j);
                        for(int create=0;create<i+j;i++){
                            path[i].resize(3);
                        }
                        path[0][0] = i;
                        path[0][1] = j;
                        path[0][2] = 1;
                        int q=0;
                        int count=0;
                        int lm=0;
                        while(lm==0){
                            if((q==matrix[i][j][0]) && (path[q][0]==par2) && (path[q][1]==par1)){
                                count++;
                                if(count>1){break;}
                            }
                            if((q==matrix[i][j][0]) && ((path[q][0]==par2) || (path[q][1]==par1))){
                                q--;
                                path[q][2]++;
                            }
                            if(path[q][2]>4){
                            q--;
                            path[q][2]++;
                            }

                            if((count==0) && (q<0)){
                            break;
                            }



                            if((q<0) && (count==1)){
                                int lm=0;
                               while(lm==0){
                                   if((q==matrix[i][j][0]) && (path[q][0]==par2) && (path[q][1]==par1)){
                               for(int temp=q;temp>0;temp--){
                                   matrix[path[q][0]][path[q][1]][1]= matrix[i][j][1];
                                   matrix[path[q][0]][path[q][1]][0]= matrix[i][j][0];
                                   matrix[par2][par1][2]=1;
                                   matrix[i][j][2]=1;
                                   }
                                    break;
                                   }
                                   if((q==matrix[i][j][0]) && ((path[q][0]==par2) || (path[q][1]==par1))){
                                       q--;
                                       path[q][2]++;
                                   }
                                   if(path[q][2]>4){
                                   q--;
                                   path[q][2]++;
                                   }
                                    int bad;




                                   if((path[q][1]<8) && (path[q][2]<=1)){ //checking for x+1 move
                                       for(int temp=q;temp>0;temp--){
                                           if((path[temp][0] == path[q][0]) && (path[temp][1] == path[q][1]+1)){
                                               bad = 1;
                                           }
                                           else{
                                               bad = 0;
                                           }
                                       }
                                       if((matrix[path[q][0]][path[q][1]+1][1] == 0) && (bad==0)){
                                           q++;
                                           path[q][0]=path[q-1][0];
                                           path[q][1]=path[q-1][1]+1;
                                           path[q-1][2]=1;
                                           path[q][2]=0;
                                           continue;
                                       }
                                   }


                                   if((path[q][0]<12)&& (path[q][2]<=2)){ //checking for y+1 move
                                       for(int temp=q;temp>0;temp--){
                                           if((path[temp][1] == path[q][1]) && (path[temp][0] == path[q][0]+1)){
                                               int bad = 1;
                                           }
                                           else{
                                               int bad = 0;
                                           }
                                       }
                                       if((matrix[path[q][0]+1][path[q][1]][1] == 0) && (bad==0)){
                                           q++;
                                           path[q][1]=path[q-1][1];
                                           path[q][0]=path[q-1][0]+1;
                                           path[q-1][2]=2;
                                           path[q][2]=0;
                                           continue;
                                       }
                                   }


                                   if((path[q][1]>0)&& (path[q][2]<=3)){ //checking for x-1 move
                                       for(int temp=q;temp>0;temp--){
                                           if((path[temp][0] == path[q][0]) && (path[temp][1] == path[q][1]-1)){
                                               int bad = 1;
                                           }
                                           else{
                                               int bad = 0;
                                           }
                                       }
                                       if((matrix[path[q][0]][path[q][1]-1][1] == 0) && (bad==0)){
                                           q++;
                                           path[q][0]=path[q-1][0];
                                           path[q][1]=path[q-1][1]-1;
                                           path[q-1][2]=3;
                                           path[q][2]=0;
                                           continue;
                                       }
                                   }


                                   if((path[q][1]>0) && (path[q][2]<=4)){ //checking for y-1 move
                                       for(int temp=q;temp>0;temp--){
                                           if((path[temp][0] == path[q][0]-1) && (path[temp][1] == path[q][1])){
                                               int bad = 1;
                                           }
                                           else{
                                               int bad = 0;
                                           }
                                       }
                                       if((matrix[path[q][0]][path[q][1]+1][1] == 0) && (bad==0)){
                                           q++;
                                           path[q][1]=path[q-1][1];
                                           path[q][0]=path[q-1][0]-1;
                                           path[q-1][2]=4;
                                           path[q][2]=0;
                                           continue;
                                       }
                                   }


                               }


                           }
                                      break;

                }









                            int bad;

                            if((path[q][1]<8) && (path[q][2]<=1)){ //checking for x+1 move
                                for(int temp=q;temp>0;temp--){
                                    if((path[temp][0] == path[q][0]) && (path[temp][1] == path[q][1]+1)){
                                        int bad = 1;
                                    }
                                    else{
                                        int bad = 0;
                                    }
                                }
                                if((matrix[path[q][0]][path[q][1]+1][1] == 0) && (bad==0)){
                                    q++;
                                    path[q][0]=path[q-1][0];
                                    path[q][1]=path[q-1][1]+1;
                                    path[q-1][2]=1;
                                    path[q][2]=0;
                                    continue;
                                }
                            }


                            if((path[q][0]<12)&& (path[q][2]<=2)){ //checking for y+1 move
                                for(int temp=q;temp>0;temp--){
                                    if((path[temp][1] == path[q][1]) && (path[temp][0] == path[q][0]+1)){
                                        int bad = 1;
                                    }
                                    else{
                                        int bad = 0;
                                    }
                                }
                                if((matrix[path[q][0]+1][path[q][1]][1] == 0) && (bad==0)){
                                    q++;
                                    path[q][1]=path[q-1][1];
                                    path[q][0]=path[q-1][0]+1;
                                    path[q-1][2]=2;
                                    path[q][2]=0;
                                    continue;
                                }
                            }


                            if((path[q][1]>0)&& (path[q][2]<=3)){ //checking for x-1 move
                                for(int temp=q;temp>0;temp--){
                                    if((path[temp][0] == path[q][0]) && (path[temp][1] == path[q][1]-1)){
                                        int bad = 1;
                                    }
                                    else{
                                        int bad = 0;
                                    }
                                }
                                if((matrix[path[q][0]][path[q][1]-1][1] == 0) && (bad==0)){
                                    q++;
                                    path[q][0]=path[q-1][0];
                                    path[q][1]=path[q-1][1]-1;
                                    path[q-1][2]=3;
                                    path[q][2]=0;
                                    continue;
                                }
                            }


                            if((path[q][1]>0) && (path[q][2]<=4)){ //checking for y-1 move
                                for(int temp=q;temp>0;temp--){
                                    if((path[temp][0] == path[q][0]-1) && (path[temp][1] == path[q][1])){
                                        int bad = 1;
                                    }
                                    else{
                                        int bad = 0;
                                    }
                                }
                                if((matrix[path[q][0]][path[q][1]+1][1] == 0) && (bad==0)){
                                    q++;
                                    path[q][1]=path[q-1][1];
                                    path[q][0]=path[q-1][0]-1;
                                    path[q-1][2]=4;
                                    path[q][2]=0;
                                    continue;
                                }
                            }


                        }


                    }
                }
            }
        i++;
        j++;
            }





























    for(int i=12;i>=0;i--){
        for(int j=0;j<9;j++){
            cout <<matrix[i][j][0];
        }
        cout <<endl;
    }


                               while(i+j!=20){
                                   if((matrix[i][j][0] != 0) && (matrix[i][j][2] = 0)){
                                       if(j + matrix[i][j][0] - 1 > 8){
                                           maxr = 8;
                                       }
                                       else{maxr = j + matrix[i][j][0] - 1;}

                                       if(j - matrix[i][j][0] + 1 < 0){
                                           maxl = 0;
                                       }
                                       else{maxr = j - matrix[i][j][0] + 1;}

                                       if(i + matrix[i][j][0] - 1 > 12){
                                       maxh = 12;
                                       }
                                       else{maxh = i + matrix[i][j][0] - 1;}

                                       for(int par1=maxl; par1<=maxr;par1++){
                                           for(int par2=i; par2<=maxh;par1++){
                                               if((matrix[par2][par1][2] = 0) && (matrix[par2][par1][0]==matrix[i][j][0])){
                                                   vector<vector<int>> path(i+j);
                                                   for(int create=0;create<i+j;i++){
                                                       path[i].resize(3);
                                                   }
                                                   path[0][0] = i;
                                                   path[0][1] = j;
                                                   path[0][2] = 1;
                                                   int q=0;
                                                   int count=0;
                                                   while(true){
                                                       if((q==matrix[i][j][0]) && (path[q][0]==par2) && (path[q][1]==par1)){
                                                      for(int temp=q;temp>0;temp--){
                                                      matrix[path[q][0]][path[q][1]][1]= matrix[i][j][1];
                                                      matrix[path[q][0]][path[q][1]][0]= matrix[i][j][0];
                                                      matrix[par2][par1][2]=1;
                                                      matrix[i][j][2]=1;
                                                      }
                                                       break;
                                                      }
                                                       }
                                                       if((q==matrix[i][j][0]) && ((path[q][0]==par2) || (path[q][1]==par1))){
                                                           q--;
                                                           path[q][2]++;
                                                       }
                                                       if(path[q][2]>4){
                                                       q--;
                                                       path[q][2]++;
                                                       }

                                                       if((count==0) && (q<0)){
                                                  break;
                }
                                                        int bad;

                                                       if((path[q][1]<8) && (path[q][2]<=1)){ //checking for x+1 move
                                                           for(int temp=q;temp>0;temp--){
                                                               if((path[temp][0] == path[q][0]) && (path[temp][1] == path[q][1]+1)){
                                                                   int bad = 1;
                                                               }
                                                               else{
                                                                   int bad = 0;
                                                               }
                                                           }
                                                           if((matrix[path[q][0]][path[q][1]+1][1] == 0) && (bad==0)){
                                                               q++;
                                                               path[q][0]=path[q-1][0];
                                                               path[q][1]=path[q-1][1]+1;
                                                               path[q-1][2]=1;
                                                               path[q][2]=0;
                                                               continue;
                                                           }
                                                       }


                                                       if((path[q][0]<12)&& (path[q][2]<=2)){ //checking for y+1 move
                                                           for(int temp=q;temp>0;temp--){
                                                               if((path[temp][1] == path[q][1]) && (path[temp][0] == path[q][0]+1)){
                                                                   int bad = 1;
                                                               }
                                                               else{
                                                                   int bad = 0;
                                                               }
                                                           }
                                                           if((matrix[path[q][0]+1][path[q][1]][1] == 0) && (bad==0)){
                                                               q++;
                                                               path[q][1]=path[q-1][1];
                                                               path[q][0]=path[q-1][0]+1;
                                                               path[q-1][2]=2;
                                                               path[q][2]=0;
                                                               continue;
                                                           }
                                                       }


                                                       if((path[q][1]>0)&& (path[q][2]<=3)){ //checking for x-1 move
                                                           for(int temp=q;temp>0;temp--){
                                                               if((path[temp][0] == path[q][0]) && (path[temp][1] == path[q][1]-1)){
                                                                   int bad = 1;
                                                               }
                                                               else{
                                                                   int bad = 0;
                                                               }
                                                           }
                                                           if((matrix[path[q][0]][path[q][1]-1][1] == 0) && (bad==0)){
                                                               q++;
                                                               path[q][0]=path[q-1][0];
                                                               path[q][1]=path[q-1][1]-1;
                                                               path[q-1][2]=3;
                                                               path[q][2]=0;
                                                               continue;
                                                           }
                                                       }


                                                       if((path[q][1]>0) && (path[q][2]<=4)){ //checking for y-1 move
                                                           for(int temp=q;temp>0;temp--){
                                                               if((path[temp][0] == path[q][0]-1) && (path[temp][1] == path[q][1])){
                                                                   int bad = 1;
                                                               }
                                                               else{
                                                                   int bad = 0;
                                                               }
                                                           }
                                                           if((matrix[path[q][0]][path[q][1]+1][1] == 0) && (bad==0)){
                                                               q++;
                                                               path[q][1]=path[q-1][1];
                                                               path[q][0]=path[q-1][0]-1;
                                                               path[q-1][2]=4;
                                                               path[q][2]=0;
                                                               continue;
                                                           }
                                                       }


                                                   }


                                           }
                                       }
                                       }
                                   i++;
                                   j++;
                                       }

                               cout << "Hello World!" << endl;
                               return 0;

                               }



