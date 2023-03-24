#lang sicp

(display "=> Exponention") (newline)

(define (expt b n)
    (if (= n 0)
        1
        (* b (expt b (- n 1)))))
        
(display (expt 2 17)) (newline)       
(display (expt 2 42)) (newline)


(define (expt-02 b n)
    (expt-iter b n 1))
(define (expt-iter b counter product)
    (if (= counter 0)
        product
        (expt-iter b
                   (- counter 1)
                   (* b product))))

(display (expt-02 2 17)) (newline)
(display (expt-02 2 42)) (newline)


(define (fast-expt b n)
    (cond ((= n 0) 1)
          ((even? n) (square (fast-expt b (/ n 2))))
          (else (* b (fast-expt b (- n 1))))))

(define (even? n)
    (= (remainder n 2) 0))
    
(define (square n)
    (* n n))
    
(display (fast-expt 2 17)) (newline)    
(display (fast-expt 2 42)) (newline)
    
    