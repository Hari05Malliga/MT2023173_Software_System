#include <stdio.h>
#include <unistd.h>

#define MAX 50

int main() {
	size_t var;
	char buffer[MAX];
	var = read (0, buffer, sizeof(buffer));
        write(1, buffer, var);
	return 0;
}
