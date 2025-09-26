#lang sicp

(display "Procedures as arguments =>") (newline)

(define (sum-integers a b)
    (if (> a b)
        0
        (+ a (sum-integers (+ a 1) b))))
        
(display (sum-integers 1 10)) (newline)


(define (cube x) (* x x x))

(define (sum-cubes a b)
    (if (> a b)
        0
        (+ (cube a)
           (sum-cubes (+ a 1) b))))
       
(display (sum-cubes 1 10)) (newline)


(define (pi-sum a b)
    (if (> a b)
        0
        (+ (/ 1.0 (* a (+ a 2)))
           (pi-sum (+ a 4) b))))
           
(pi-sum 1 1000)
(/ 3.1415 8) 


(define (sum term a next b)
    (if (> a b)
        0
        (+ (term a)
           (sum term (next a) next b))))
           
(define (inc n) (+ n 1))
(define (sum-cubes-02 a b)
    (sum cube a inc b))

(sum-cubes-02 1 10)


(define (identity x) x)
(define (sum-integers-02 a b)
    (sum identity a inc b))

(sum-integers-02 1 10)


(define (pi-sum-02 a b)
    (define (pi-term x)
        (/ 1.0 (* x (+ x 2))))
    (define (pi-next x)
        (+ x 4))
    (sum pi-term a pi-next b))
    
(* 8 (pi-sum-02 1 1000))


(define (integral f a b dx)
    (define (add-dx x)
        (+ x dx))
    (* (sum f (+ a (/ dx 2.0)) add-dx b)
       dx))

(integral cube 0 1 0.01)
(integral cube 0 1 0.001)
