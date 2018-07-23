FROM alpine

RUN apk add --no-cache build-base python ca-certificates git lua-dev
RUN update-ca-certificates

WORKDIR /termbox
RUN git clone https://github.com/nsf/termbox.git .
RUN ./waf configure --prefix=/usr \
    && ./waf \
    && ./waf install

WORKDIR /app
COPY . .

RUN make clean
RUN make

ENV TERM xterm
CMD ["./etac"]