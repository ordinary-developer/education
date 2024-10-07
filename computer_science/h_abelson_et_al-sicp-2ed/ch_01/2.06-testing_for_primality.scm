#lang sicp

(display "=> Example: Testing for Primality") (newline)

(define (smallest-divisor n)
    (find-divisor n 2))
(define (find-divisor n test-divisor)
    (cond ((> (square test-divisor) n) n)
          ((divides? test-divisor n) test-divisor)
          (else (find-divisor n (+ test-divisor 1)))))
(define (divides? a b) (= (remainder b a) 0))
(define (square n) (* n n))

(define (prime? n) (= n (smallest-divisor n)))

(prime? 17)
(prime? 42)


(define (smallest-divisor-02 n)
    (define (find-divisor n test-divisor)
        (define (divides? a b) (= (remainder a b) 0))
        (define (square a) (* a a))

        (cond ((> (square test-divisor) n) n)
              ((divides? n test-divisor) test-divisor)
              (else (find-divisor n (+ test-divisor 1)))))

    (find-divisor n 2))

(define (prime-02? n) (= n (smallest-divisor-02 n)))

(prime-02? 17)
(prime-02? 42)


; The Fermat test
(define (expmod base exp m)
    (define (even? n) (= (remainder n 2) 0))
    (define (square n) (* n n))

    (cond ((= exp 0) 1)
          ((even? exp) (remainder (square (expmod base (/ exp 2) m)) m))
          (else (remainder (* base (expmod base (- exp 1) m)) m))))

(define (fermat-test n)
    (define (try-it a)
        (= (expmod a n n) a))
    (try-it (+ 1 (random (- n 1)))))

(define (fast-prime? n times)
    (cond ((= times 0) true)
          ((fermat-test n) (fast-prime? n (- times 1)))
          (else false)))

(fermat-test 17)
(fermat-test 42)
(fast-prime? 17 10)
(fast-prime? 42 10)
