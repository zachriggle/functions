NAME=functions
ROOT=$(shell git rev-parse --show-toplevel)
RUN=docker run --net=none --init --rm -h $(NAME) -it -v $(ROOT):/root

all: build run

build:
	docker build -t $(NAME) .

run: build
	$(RUN) --entrypoint /usr/bin/make $(NAME):latest

shell: build
	$(RUN) --entrypoint /bin/sh $(NAME):latest

.PHONY: all
