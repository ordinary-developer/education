;; expressions
(display "[expressions] =>") (newline)

(display 486) (newline) (newline)

(display (+ 137 439)) (newline)
(display (- 1000 334)) (newline)
(display (* 5 99)) (newline)
(display (/ 10 5)) (newline)
(display (+ 2.7 10)) (newline)(newline)

(display (+ 21 35 12 7)) (newline)
(display (* 25 4 12)) (newline)

(newline)
(display (+ (* 3 5) (- 10 6))) (newline)

(newline)
(display (+ (* 3 (+ (* 2 4) (+ 3 5))) (+ (- 10 7) 6))) (newline)
(display 
    (+  (* 3
            (+ (* 2 4)
                (+ 3 5)))
        (+ (- 10 7)
             6))
) (newline)             


;; naming and the environment
(newline)(newline)
(display "[naming and the environment] =>") 

(newline)
(define size 2)
(display size) (newline)
(display (* 5 size)) (newline)

(newline)
(define pi 3.14159)
(define radius 10)
(display (* pi (* radius radius))) (newline)

(newline)
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

