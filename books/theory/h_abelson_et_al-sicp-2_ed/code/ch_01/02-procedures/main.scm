;; the "linear recursion and iteration" section
(display "linear recursion and iteration =>") (newline)
(define (factorial n)
    (if (= n 1)
        1
        (* n (factorial (- n 1)))))
    
(display (factorial 6)) (newline)

(define (factorial n)
    (fact_iter 1 1 n))
(define (fact_iter product counter max_count)
    (if (> counter max_count)
        product
        (fact_iter (* counter product)
                   (+ counter 1)
                   max_count))) 

(display (factorial 6)) (newline)

(define (factorial n)
    (define (iter product counter)
        (if (> counter n)
            product
            (iter (* counter product) (+ counter 1))))
    (iter 1 1))
    
(display (factorial 6)) (newline)


;; tree recursion
(newline) (newline)
(display "[tree recursion] =>") (newline)

(define (fib n)
    (cond ((= n 0) 0)
          ((= n 1) 1)
          (else (+ (fib (- n 1)) (fib (- n 2))))))
(display (fib 17)) (newline)

(define (fib n)
    (fib_iter 1 0 n))
(define (fib_iter a b count)
    (if (= count 0)
        b
        (fib_iter (+ a b) a (- count 1))))
(display (fib 17)) (newline)

(define (count_change amount) (cc amount 5))
(define (cc amount kinds_of_coins)
    (cond ((= amount 0) 1)
          ((or (< amount 0) (= kinds_of_coins 0)) 0)
          (else (+ (cc amount
                       (- kinds_of_coins 1)) 
                   (cc (- amount 
                          (first_denomination kinds_of_coins)) 
                       kinds_of_coins)))))
(define (first_denomination kinds_of_coins)
    (cond ((= kinds_of_coins 1) 1)
          ((= kinds_of_coins 2) 5) 
          ((= kinds_of_coins 3) 10) 
          ((= kinds_of_coins 4) 25) 
          ((= kinds_of_coins 5) 50) ))
(display (count_change 100)) (newline)


;; exponentiation
(newline)(newline)
(display "[exponentiation] =>")(newline)

(define (exponent b n)
    (if (= n 0)
        1
        (* b (exponent b (- n 1)))))
(display (exponent 18 3))(newline)
(display (exponent 17 3))(newline)

(define (exponent b n)
    (exponent_iter b n 1))
(define (exponent_iter b counter product)
    (if (= counter 0)
        product
        (exponent_iter b
                       (- counter 1)
                       (* b product))))
(display (exponent 18 3))(newline)
(display (exponent 17 3))(newline)

(define (fast_exp b n)
    (cond ((= n 0) 1)
          ((even? n) (square (fast_exp b (/ n 2))))
          (else (* b (fast_exp b (- n 1))))))
(define (even? n)
    (= (remainder n 2) 0))
(define (square n)
    (* n n))
(display (fast_exp 18 3))(newline)


;; greatest common divisors
(newline)(newline)
(display "[greatest common divisors] =>") (newline)

(define (gcd a b)
    (if (= b 0)
        a
        (gcd b (remainder a b))))
(display (gcd 8 4))(newline)
