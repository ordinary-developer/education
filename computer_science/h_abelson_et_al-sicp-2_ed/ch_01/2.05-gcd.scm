#lang sicp

(display "=> Greatest Common Divisors") (newline)

(define (gcd a b)
    (if (= b 0)
        a
        (gcd b (remainder a b))))
        
(gcd 17 42) (newline)
(gcd 42 17) (newline)
