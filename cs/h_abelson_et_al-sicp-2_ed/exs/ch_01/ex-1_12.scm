#lang sicp

; [exercise] =>
; The folloing pattern of numbers is called
; Pascal's triangle
;        1
;      1   1
;    1   2   1
;  1   3   3   1  
;1   4   6   4   1 
;
; The numbers at the edge of the triangle are all 1, and each
; number inside the triangle is the sum of the two numbers
; above it. Write a procedure that computes elements of 
; Pascals' triangle by means of a recusive process



; -------------
; [solution] =>
(display "'Pascal's triangle' =>") (display "\n")

; util funcs
(define (output-test name ret)
    (display (if ret "[  OK  ]" "[FAILED]"))
    (display " ") (display name) (newline))
    
(define (abs num) (if (< num 0) (- num) num))
(define (are-equal num1 num2) (< (abs (- num1 num2)) 0.001))

; logic
(define (str-len idx) (+ idx 1))    

(define str-len-assert
    (and (are-equal 1 (str-len 0))
         (are-equal 2 (str-len 1))
         (are-equal 3 (str-len 2))
         (are-equal 5 (str-len 4))
         (are-equal 18 (str-len 17))
         (are-equal 43 (str-len 42))))
(output-test "'str-len' func" str-len-assert)


(define (low-idx str-idx) 0)
(define (high-idx str-idx) (- (str-len str-idx) 1))

(define low-high-idx-assert
    (and (are-equal 0 (low-idx 0))
         (are-equal 0 (high-idx 0))
         (are-equal 0 (low-idx 1))
         (are-equal 1 (high-idx 1))
         (are-equal 0 (low-idx 2))
         (are-equal 2 (high-idx 2))
         (are-equal 0 (low-idx 3))
         (are-equal 3 (high-idx 3))
         (are-equal 0 (low-idx 4))
         (are-equal 4 (high-idx 4))))
(output-test "'low-high-idx' func" low-high-idx-assert)


(define (coef str-idx idx)
    (cond ((< str-idx 0) (- 1))
          ((or (< idx 0) (> idx (- (str-len str-idx) 1))) (- 1))
          ((= str-idx 0) 1)
          ((= str-idx 1) 1)
          ((or (= (low-idx str-idx) idx) (= (high-idx str-idx) idx)) 1)
          (else (+ (coef (- str-idx 1) (- idx 1))
                   (coef (- str-idx 1) idx)))
    ) 
)

(define coef-assert
    (and (are-equal 1 (coef 0 0))
         (are-equal 1 (coef 1 0))
         (are-equal 1 (coef 1 1))
         (are-equal 1 (coef 2 0))
         (are-equal 2 (coef 2 1))
         (are-equal 1 (coef 2 2))
         (are-equal 1 (coef 3 0))
         (are-equal 3 (coef 3 1))
         (are-equal 3 (coef 3 2))
         (are-equal 1 (coef 3 3))
         (are-equal 1 (coef 4 0))
         (are-equal 4 (coef 4 1))
         (are-equal 6 (coef 4 2))
         (are-equal 4 (coef 4 3))
         (are-equal 1 (coef 4 4))

         (are-equal (- 1) (coef (- 1) 0))
         (are-equal (- 1) (coef (- 10) 0))
         (are-equal (- 1) (coef 0 1))
         (are-equal (- 1) (coef 0 (- 1)))
         (are-equal (- 1) (coef 1 2))
         (are-equal (- 1) (coef 1 (- 1)))
         (are-equal (- 1) (coef 2 (str-len 2)))
         (are-equal (- 1) (coef 3 (str-len 3)))
         (are-equal (- 1) (coef 4 (str-len 4)))
    ))
(output-test "'coef' func" coef-assert)
