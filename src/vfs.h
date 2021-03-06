#ifndef __vfs_h
#define __vfs_h

#include <time.h>
#define MAX_FILE_OPEN 10

typedef struct tm  datetime;

struct ml {
  unsigned char	dev_id;
  unsigned char 	mount_point;
  unsigned char	fs[4];
} mount_list[2];

typedef struct {
  unsigned char id; //max 256 files
  unsigned short dir_cluster;
  unsigned char dev_id;
  unsigned int cur_r_of;
  unsigned int cur_w_of;
  unsigned char modes;
  unsigned char flags;
} FD;

typedef struct {
  unsigned char dev_id;
  unsigned char *data;
  int  size;
  int (*write)(unsigned char *ptr, int offset, int size);
  int (*read)(unsigned char *ptr,  int offset, int size);
  int (*init)(unsigned int diskSize);
  int (*deinit)();
} DISK;

typedef struct {
  unsigned char	filename[8];
  unsigned char	ext[4];
  unsigned char	file_attr;
  datetime   dt;
  unsigned int	f_size;
  unsigned int  dirent;
  unsigned int  cluster;
} directory;

int readDisk(unsigned char dev_id, unsigned char *ptr, int offset, int size);
int writeDisk(unsigned char dev_id, unsigned char *ptr, int offset, int size);

/* Fat definitions */
int mount(int dev_id);
int format(int dev_id);
int read(unsigned dev_id, int block_no,unsigned char *buffer, int offset, int bytes);
int write(unsigned dev_id, int block_no,unsigned char *buffer, int offset, int bytes);
#endif
