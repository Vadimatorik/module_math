#**********************************************************************
# Для сборки module_math.
#**********************************************************************
MODULE_MATH_H_FILE			:= $(shell find module_math/ -maxdepth 3 -type f -name "*.h" )
MODULE_MATH_CPP_FILE		:= $(shell find module_math/ -maxdepth 3 -type f -name "*.c" )
MODULE_MATH_DIR				:= $(shell find module_math/ -maxdepth 3 -type d -name "*" )
MODULE_MATH_PATH			:= $(addprefix -I, $(MODULE_MATH_DIR))
MODULE_MATH_OBJ_FILE		:= $(addprefix build/obj/, $(MODULE_MATH_CPP_FILE))
MODULE_MATH_OBJ_FILE		:= $(patsubst %.c, %.o, $(MODULE_MATH_OBJ_FILE))

build/obj/module_math/%.o:	module_math/%.c $(USER_CFG_H_FILE)
	@echo [CC] $<
	@mkdir -p $(dir $@)
	@$(CC) $(C_FAT_FS_FLAGS) $(MODULE_MATH_PATH) $(USER_CFG_PATH) $(FAT_FS_OPTIMIZATION) -c $< -o $@

# Добавляем к общим переменным проекта.
PROJECT_PATH			+= $(MODULE_MATH_PATH)
PROJECT_OBJ_FILE		+= $(MODULE_MATH_OBJ_FILE)