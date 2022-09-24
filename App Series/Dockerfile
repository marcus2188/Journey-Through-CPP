FROM gcc:latest
COPY . /pizzashop
WORKDIR /pizzashop
RUN g++ -o pizzashopbin pizzashop.cpp
CMD ["./pizzashopbin"]