;; linear recursion and iteration
(display "[linear recursion and iteration] =>") (newline)

(define (factorial n)
    (if (= n 1)
        1
        (* n (factorial (- n 1)))))   
(display (factorial 3)) (newline)
(display (factorial 4)) (newline)
(display (factorial 5)) (newline)

(define (factorial n)
    (fact_iter 1 1 n))
(define (fact_iter product counter max_count)
    (if (> counter max_count)
        product
        (fact_iter (* counter product)
                   (+ counter 1)
                   max_count)))
(display (factorial 3)) (newline)
(display (factorial 4)) (newline)
(display (factorial 5)) (newline)

(define (factorial n)
    (define (iter product counter)
        (if (> counter n)
            product
            (iter (* counter product) (+ counter 1))))
        
    (iter 1 1))
(display (factorial 3)) (newline)
(display (factorial 4)) (newline)
(display (factorial 5)) (newline)
