FROM ubuntu:22.04
RUN apt-get update && apt-get install -y g++ make
WORKDIR /usr/src/cpp-on-rails
COPY . .
RUN make
EXPOSE 8080
CMD ["./cpp-on-rails-prod"]
