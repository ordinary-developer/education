#lang sicp

(display "=> Tree recursion") (display "\n")

(define (fib-recur n)
    (cond ((= n 0) 0)
          ((= n 1) 1)
          (else (+ (fib-recur (- n 1))
                   (fib-recur (- n 2))))))

(fib-recur 17)
(fib-recur 10)
(fib-recur 5)
(fib-recur 1)
(fib-recur 0)

(define (fib-iter n)
    (define (iter a b count)
        (if (= count 0)
            b
            (iter (+ a b) a (- count 1))))

    (iter 1 0 n))

(fib-iter 17)
(fib-iter 10)
(fib-iter 5)
(fib-iter 1)
(fib-iter 0)
