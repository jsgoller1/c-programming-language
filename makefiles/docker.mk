### Dockerized Linux workspace for consistent environment
docker-clean:
	-docker stop ubuntu
	-docker rm ubuntu

docker: docker-clean
	docker pull ubuntu
	docker run \
	-dt \
	--name ubuntu \
	-v `pwd`:/k-and-r \
	ubuntu
	docker exec ubuntu apt-get update
	docker exec ubuntu apt-get install -y make valgrind clang clang-tools cdecl perl

shell:
	docker exec -it ubuntu /bin/bash

workspace: docker-clean docker shell
