# Inputs
CXX ?= clang++
AR ?= llvm-ar


INCLUDEDIR := include
BUILDDIR := build
SRCDIR := src
OBJS :=\
  $(BUILDDIR)/blendmode.o       \
  $(BUILDDIR)/circle.o          \
  $(BUILDDIR)/font.o            \
  $(BUILDDIR)/madsfml.o         \
  $(BUILDDIR)/math.o            \
  $(BUILDDIR)/rectangle.o       \
  $(BUILDDIR)/renderstates.o    \
  $(BUILDDIR)/rendertexture.o   \
  $(BUILDDIR)/shader.o          \
  $(BUILDDIR)/sprite.o          \
  $(BUILDDIR)/text.o            \
  $(BUILDDIR)/texture.o         \
  $(BUILDDIR)/transform.o       \
  $(BUILDDIR)/vertex.o          \
  $(BUILDDIR)/vertexarray.o     \
  $(BUILDDIR)/vertexbuffer.o    \
  $(BUILDDIR)/view.o            \
  $(BUILDDIR)/window.o

MADLIB_RUNTIME_HEADERS_PATH := "$(shell madlib config runtime-headers-path)"
MADLIB_RUNTIME_LIB_HEADERS_PATH := "$(shell madlib config runtime-lib-headers-path)"

build: prepare build/libmadsfml.a print_done

prepare:
	@mkdir -p build

print_done:
	@echo "build done.\noutput: build/libmadsfml.a"

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -g -I$(INCLUDEDIR) -I$(MADLIB_RUNTIME_HEADERS_PATH) -I$(MADLIB_RUNTIME_LIB_HEADERS_PATH) -std=c++17 -O1 -fPIC $(CXXFLAGS) -c $< -o $@

build/libmadsfml.a: $(OBJS)
	$(AR) rc $@ $^
