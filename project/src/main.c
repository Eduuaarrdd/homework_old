#include <main.h>

char* date;

int main(int argc, const char **argv) {
	if (argc != 2) {
		return -1;
    	}
	    	
	const char *path_to_eml = argv[1];
	FILE *fd= fopen(path_to_eml, "r");
    
	if (fd == NULL) {
		printf(access_error);
		return -1;
	}
	char* data = mmap (NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	close (fd);
	extract_str(*date);	
    	return 0;
}
