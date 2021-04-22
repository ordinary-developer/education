;; expressions
(display "=> expressions") (newline)
(display 486) (newline)

(display (+ 137 349)) (newline)
(display (- 1000 334)) (newline)
(display (* 5 99)) (newline)
(display (/ 10 5)) (newline)
(display (+ 2.7 10)) (newline)

(display (+ 21 35 12 7)) (newline)
(display (* 25 4 12)) (newline)

(display (+ (* 3 5) (- 10 6))) (newline)

(display (+ (* 3 (+ (* 2 4) (+ 3 5))) (+ (- 10 7) 6))) (newline)
(display 
(+ (* 3
      (+ (* 2 4)
         (+ 3 5)))
   (+ (- 10 7)      
       6))
) (newline)         


;; naming and the environment
(display "=> naming and the environment") (newline)
(define size 2)
(display size) (newline)
(display (* 5 size)) (newline)

(define pi 3.14159)
(define radius 10)
(display (* pi (* radius radius))) (newline)
(define circumference (* 2 pi radius))
(display circumference) (newline)


;; evaluating combinations
(display "=> evaluating combinations") (newline)
(display
(* (+ 2 (* 4 6)) 
   (+ 3 5 7))
) (newline)


;; compound procedures
(display "compound procedures =>") (newline)
(define (square x) (* x x))
(display (square 21))(newline)
(display (square (+ 2 5))) (newline)
(display (square (square 3))) (newline)

(define (sum_of_squares x y)
    (+ (square x) (square y)))
(display (sum_of_squares 3 4)) (newline)

(define (f a)
    (sum_of_squares (+ a 1) (* a 2)))
(display (f 5)) (newline)


;; the substitution model
;; # Applicative-order evalution
;; The interpreter first evaluates the operator and operands
;; and then applies the resulting arguments.
;;
;; # Normal-order evalution
;; The interpreter will not evaluate the operatns 
;; unitl their values were needed.


;; conditional expressions and predicates
(display "conditional expressions and predicates =>") (newline)
(define (abs x)
    (cond ((> x 0) x)
          ((= x 0) 0)
          ((< x 0) (- x))))
(display (abs 42)) (newline)
(display (abs (- 42))) (newline)
(display (abs 0)) (newline)

(define (abs x)
    (cond ((< x 0) (- x))
          (else x)))
(display (abs 42)) (newline)
(display (abs (- 42))) (newline)
(display (abs 0)) (newline)

(define (abs x)
    (if (< x 0)
        (- x)
        x))
(display (abs 42)) (newline)
(display (abs (- 42))) (newline)
(display (abs 0)) (newline)

(define x 7)
(display (and (> x 5) (< x 10))) (newline)

(define (>= x y) (or (> x y) (= x y)))
(display (>= 17 42)) (newline)
(display (>= 42 17)) (newline)

(define (>= x y) (not (< x y)))
(display (>= 17 42)) (newline)
(display (>= 42 17)) (newline)


;; example: square roots by Newton's Method
(display "example: square roots by Newton's Method =>") (newline)
(define (square x) (* x x))
(define (sqrt x)
    (define (sqrt_iter guess x)
        (if (good_enough? guess x)
            guess
            (sqrt_iter (improve guess x) x)))

    (define (good_enough? guess x)
        (< (abs (- (square guess) x)) 0.001))
    (define (improve guess x)
        (average guess (/ x guess)))
    (define (average x y)
        (/ (+ x y) 2))

    (sqrt_iter 1.0 x) 
)

(display (sqrt 9)) (newline)
(display (sqrt (+ (sqrt 2) (sqrt 3)))) (newline)
(display (square (sqrt 1000))) (newline)


;; procedures as black-box abstractions
(newline)(newline)
(display "[procedures as black-box abstractions =>") (newline)

(define (square x) (* x x))
(display (square 2.0)) (newline)

(define (square x) (exp (double (log x))))
(define (double x) (+ x x))
(display (square 2.0)) (newline)


;; internal definitions and block structure
(newline) (newline)
(display "[internal definitions and block structure] =>") (newline)

(define (sqrt x)
    (define (square x) (* x x))
    (define (good_enough? guess x)
        (< (abs (- (square guess) x)) 0.001))
    (define (average x y) (/ (+ x y) 2))
    (define (improve guess x) (average guess (/ x guess)))
    (define (sqrt_iter guess x)
        (if (good_enough? guess x)
            guess
            (sqrt_iter (improve guess x) x)))
    
    (sqrt_iter 1.0 x))
(display (sqrt 2.0)) (newline)

(define (sqrt x)
    (define (average a b) (/ (+ a b) 2))
    (define (square a) (* a a))
    (define (good_enough? guess)
        (< (abs (- (square guess) x)) 0.001))
    (define (improve guess)
        (average guess (/ x guess)))
    (define (sqrt_iter guess)
        (if (good_enough? guess)
            guess
            (sqrt_iter (improve guess))))
    
    (sqrt_iter 1.0))
(display (sqrt 2.0)) (newline)
