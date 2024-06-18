
#include "libtree.h"
#include <time.h>

int main()
{
        srand(time(0));
        binTree tree;
        createTree(&tree);
        size_t size = rand() % 20 + 1;
        
        for (size_t i = 0 ; i < size; i++) {
                int x = rand() % 100 + 1;
                insertTree(x, &tree);
        }
        printTree(&tree);
        printf("\n");
        printf("Total nodes:: %d\n", countNoTree(&tree));
        printf("Tree's height: %d\n", heightTree(&tree));

        printf("Pre Ordem: ");
        preOrdem(&tree);
        printf("\n");

        printf("Ordem: ");
        Ordem(&tree);
        printf("\n");

        printf("Post Ordem: ");
        postOrdem(&tree);
        printf("\n");

        printf("Path length: %d\n", pathLength(&tree, 0));
        printf("Intern path length: %d\n", intPathLength(&tree, 0));
        printf("Extern path length: %d\n", extPathLength(&tree, 0));

        freeTree(&tree);
        return 0;
}
