# 定义变量
SUBDIRS := $(wildcard */)

# 默认目标
all: subdirs

# 递归进入子目录并运行 make
subdirs:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

# 清理所有子目录
clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

.PHONY: all subdirs clean