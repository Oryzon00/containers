CXX				=	c++

CXXFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g3

OBJS_DIR		=	.objs

$(OBJS_DIR)		:
					@mkdir -p $(OBJS_DIR)

# %.o : %.cpp
# 	$(CXX) $(CXXFLAGS) -o $@ -c $< 

#--------------------------------------------------------------------------------------------------#
#											VECTOR												   #
#--------------------------------------------------------------------------------------------------#

VECTOR_SRCS		=

VECTOR_OBJS 	= 	$(addprefix $(OBJS_DIR)/, $(notdir $(VECTOR_SRCS:%.cpp=%.o)))

$(OBJS_DIR)/%.o	: 	srcs/vector/%.cpp
					@echo "Generating vector object..." $@
					@$(CXX) $(CXXFLAGS) -c $< -o $@

vector			:	$(OBJS_DIR) $(VECTOR_OBJS)
					@$(CXX) $(CXXFLAGS) $(VECTOR_OBJS) -o vector
					@echo \n
					@echo "Vector: Done!"

#--------------------------------------------------------------------------------------------------#
#											MAPS												   #
#--------------------------------------------------------------------------------------------------#


#--------------------------------------------------------------------------------------------------#
#											STACK												   #
#--------------------------------------------------------------------------------------------------#


#--------------------------------------------------------------------------------------------------#
#											GENERAL												   #
#--------------------------------------------------------------------------------------------------#

all			:	map vector stack

		
clean		:	
				@rm -rf $(OBJS_DIR)
				@echo "Objects cleaned!"


fclean		:	clean
				@rm -f vector
				@rm -f maps
				@rm -f stack
				@echo "Executables cleaned!"


re			:	fclean all


.PHONY		:	clean fclean re all vector stack map 
