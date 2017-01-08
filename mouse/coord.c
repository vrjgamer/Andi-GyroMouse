#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    char str[200];
    int sim_fd;
    int x, y, key;
    char buffer[10];

	x = 0;
	y = 0;
	const int sensitivity = 1;
    
    // Open the sysfs coordinate node
    sim_fd = open("/sys/devices/platform/virmouse/vmevent", O_RDWR);
    if (sim_fd < 0) {
        perror("Couldn't open vms coordinate file\n");
        exit(-1);
    }
    while (1) {
        x = 0;
        y = 0;
        
        gets(str);
        memmove(str, str+18, strlen(str));

        sscanf(str, "%d %d %d", &x, &y, &key);
        
        // Convey simulated coordinates to the virtual mouse driver
        
	    x *= -sensitivity;
	    y *= sensitivity;
        
	    sprintf(buffer, "%d %d %d", x, y, key);
	    write(sim_fd, buffer, strlen(buffer));
	    fsync(sim_fd);
    }
    
    close(sim_fd);
}
