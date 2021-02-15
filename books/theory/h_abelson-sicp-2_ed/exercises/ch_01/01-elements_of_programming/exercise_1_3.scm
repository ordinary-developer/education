;; define a procedure that takes three numbers
;; as arguments and returns the sum of the squares of the two
;; larger numbers

(define (func param1 param2 param3)
    (define (square p) (* p p))
    (define maximum (max param1 param2 param3))
    (cond ((= maximum param1) (+ (square param1) (square (max param2 param3))))
          ((= maximum param2) (+ (square param2) (square (max param1 param3))))
          ((= maximum param3) (+ (square param3) (square (max param1 param2)))))        
)

(display (func 1 2 3)) (newline)
(display (func 3 2 1)) (newline)
(display (func (- 1) (- 2) (- 3))) (newline)
(display (func (- 3) (- 2) (- 1))) (newline)
(display (func 0.1 0.2 0.3)) (newline)
(display (func (- 0.1) (- 0.2) (- 0.3))) (newline)
