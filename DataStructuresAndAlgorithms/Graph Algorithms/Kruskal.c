#include<cstdio>

int adj[50][50];										//An Adjacency Matrix for creating graph
int no_of_vertices, status[50];							//To find out if the vertex is already visited or not

int front = -1, rear = -1;

void create_graph()
{
	int i, j;
	printf("Enter no of vertices: ");
	scanf_s("%d", &no_of_vertices);
	const int max_edge = (no_of_vertices * (no_of_vertices - 1)) / 2;

	printf("\nInstructions: \nYou have to enter edges for each vertices, we will provide you the no of counts.\nIf any where you have to exit, enter (-1 -1).\nN.B. Don't press any value which is equal to max no of vertices\nor forming any loop structure.\n");
	int source, destin;

	for (i = 0; i < no_of_vertices; i++)
		for (j = 0; j < no_of_vertices; j++)
			adj[i][j] = 0;

	for (i = 1; i <= max_edge; i++)
	{
		printf("Enter edges for %d: ", i);
		scanf_s("%d%d", &source, &destin);

		if (source == -1 && destin == -1)				//Base Case
			break;
		if ((source == -1 || destin == -1) || (source == no_of_vertices) || (destin == no_of_vertices))
		{
			printf("Sorry, you have entered an incorrect option, redirecting again\n");
			i--;
		}
		else
		{
			adj[source][destin] = 1;
			adj[destin][source] = 1;
		}
	}
}

