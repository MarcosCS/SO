/*
 *  Ausín Román,Pablo
 *  Arias Cárdenas,Andrés Felipe
 *  Sánchez Louzán,Daniel
 */
/*****************************************************************/
/***************** SISTEMAS OPERATIVOS 2018 **********************/
/*****************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sched.h>
#include<errno.h>


extern int pruebaanadirOnetoOne(int position[],int NumP, int Nsleep);


const char *NamesProcess[6]={"reservas","administracion","pagos","consultas","largo","anulaciones"};

int main (int argc, char *argv[]){
  

  int num_prueba;
  num_prueba=atoi(argv[1]);
  struct sched_param nodo;
  nodo.sched_priority = 99;
  if(sched_setscheduler(0,SCHED_FIFO,&nodo)!=0)
    printf("Error al asignar prioridad a pruebas\n");

	switch(num_prueba){

	        case 1 : {int position[4]={1,2,5,3};
		         pruebaanadirOnetoOne(position,3,2);
			 break;}

	        case 2 : {int position[5]={3,2,2,1,2};
		         pruebaanadirOnetoOne(position,4,0);
			 break;}

		case 3 : {int position[5]={2,3,1,3,3};
		         pruebaanadirOnetoOne(position,4,0);
			 break;}

		case 4 :{int position[4]={2,2,2,2};
		         pruebaanadirOnetoOne(position,3,2);
			 break;}

		case 5 : {int position[4]={0,0,0,0};
		         pruebaanadirOnetoOne(position,3,2);
			 break;}

		case 6 : {int position[4]={3,3,3,3};
		         pruebaanadirOnetoOne(position,3,0);
			 break;}

	        case 7 : {int position[4]={1,1,1,1};
		         pruebaanadirOnetoOne(position,3,0);
			 break;}	

	        case 8 : {int position[6]={1,2,5,2,1,3};
		         pruebaanadirOnetoOne(position,5,2);
			 break;}

	        case 9 : {int position[6]={1,1,1,1,1,1};
		         pruebaanadirOnetoOne(position,5,2);
			 break;}

		case 10 : {int position[6]={2,2,2,2,2,1};
		          pruebaanadirOnetoOne(position,5,4);
			  break;}

		case 11 : {int position[6]={3,3,3,3,3,2};
		          pruebaanadirOnetoOne(position,5,4);
			  break;}
	        case 12 : {int position[1]={4};
		          pruebaanadirOnetoOne(position,0,0);
			  break;}

	
		default:
		printf("Selecciona una prueba al invocar\n");
				break;
	}
	printf("Acaba la prueba\n");
	return 0;
}


//Prueba_1:  Se crean 5 procesos de reserva y se intenta añadir uno de prioridad mínima (eventos)


int pruebaanadirOnetoOne(int position[],int NumP, int Nsleep){
  int i;
  pid_t PID;
  for(i=0;i<NumP;i++){
  PID=fork();

  switch(PID)
    {
        case -1: printf("Error al crear el proceso hijo\n");
	         exit(1);
	         break;
    case 0 :
                 execl(NamesProcess[position[i]],NULL);
		 break;
        default :
                 break;
    }

  }

   PID=fork();

  switch(PID)
    {
        case -1: printf("Error al crear el proceso hijo\n");
	         exit(1);
	         break;
    case 0 : sleep(Nsleep);
                 execl(NamesProcess[position[NumP]],NULL);
		 break;
        default :
                 break;
    }
  while((PID=wait(NULL))>0){
  }
  

  return 0;
}
