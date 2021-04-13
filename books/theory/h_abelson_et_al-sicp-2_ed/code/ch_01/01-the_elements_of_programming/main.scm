;; expressions
(display "[expressions] =>") (newline)
(display 486)
(display (+ 137 349)) (newline)
(display (* 5 99)) (newline)
(display (/ 10 5)) (newline)
(display (+ 2.7 10)) (newline)

(newline)
(display (+ 21 35 12 7)) (newline)
(display (* 25 4 12)) (newline)

(newline)
(display (+ (* 3 5) (- 10 6))) (newline)

(newline)
(display (+ (* 3 (+ (* 2 4) (+ 3 5))) (+ (- 10 7) 6))) (newline)
(display 
(+ (* 3
      (+ (* 2 4)
         (+ 3 5)))
   (+ (- 10 7)
      6))
) (newline)           


;; naming and the environment
(display "[naming and the environment] =>") (newline)
(define size 2)
(display size) (newline)
(display (* 5 size)) (newline)

(define pi 3.14159)
(define radius 10)
(display (* pi (* radius radius))) (newline)
(define circumference (* 2 pi radius))
(display circumference) (newline)


;; evaluating combinations
(newline)(newline)
(display "[evaluating combinations] =>") (newline)
(display
    (* (+ 2 (* 4 6))
       (+ 3 5 7))
) (newline)


;; compound procedures
(newline)(newline)
(display "[compound procedures] =>") (newline)
(define (square x) (* x x))
(display (square 21)) (newline)
(display (square (+ 2 5))) (newline)
(display (square 3)) (newline)

(newline)
(define (sum_of_squares x y)
    (+ (square x) (square y)))
(display (sum_of_squares 3 4)) (newline)

(define (f a)
    (sum_of_squares (+ a 1) (* a 2)))
(display (f 5)) (newline)

(newline)
(define (abs x)
    (cond ((> x 0) x)
          ((= x 0) 0)
          ((< x 0) (-x))))
(display (abs 42)) (newline)

(define (abs x)
    (cond ((< x 0) (-x))
          (else x)))
(display (abs 42)) (newline)

(define (abs x)
    (if (< x 0) (- x) x))
(display (abs 42)) (newline)

(define x 2)
(define undef_cond
    (cond ((< x 2) "true"))
)
(display undef_cond) (newline) 

(newline)
(define x 7)
(define assert (and (> x 5) (< x 10)))
(display assert) (newline)

(define (gtoe x y) (or (> x y) (= x y)))
(display (gtoe 5 4)) (newline)

(define (gtoe x y) (not (< x y)))
(display (gtoe 5 4)) (newline)


;; example: square roots by Newton's Method
(newline)(newline)
(display "[example: square roots by Newton's Method] =>") (newline)
(define (sqrt x) (sqrt_iter 1.0 x))

(define (sqrt_iter guess x)
    (if (good_enough? guess x)
        guess
        (sqrt_iter (improve guess x) x)))

(define (good_enough? guess x)
    (< (abs (- (* guess guess) x)) 0.001))

(define (improve guess x)
    (average guess (/ x guess)))

(define (average x y)
    (/ (+ x y) 2))


(display (sqrt 9)) (newline)
(display (sqrt (+ 100 37))) (newline)
(display (sqrt (+ (sqrt 2) (sqrt 3)))) (newline)
(display (* (sqrt 1000) (sqrt 1000))) (newline)


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
