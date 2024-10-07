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



; --------------------
; yet another solution (works only for valid indices)
; rows and columns start with 1
(define (coef-02 row col)
    (if (or (= col 1) (= col row))
        1
        (+ (coef-02 (- row 1) (- col 1))
           (coef-02 (- row 1) col))))

(define coef-assert-02
    (and (are-equal 1 (coef-02 1 1))
         (are-equal 1 (coef-02 2 1))
         (are-equal 1 (coef-02 2 2))
         (are-equal 1 (coef-02 3 1))
         (are-equal 2 (coef-02 3 2))
         (are-equal 1 (coef-02 3 3))
         (are-equal 1 (coef-02 4 1))
         (are-equal 3 (coef-02 4 2))
         (are-equal 3 (coef-02 4 3))
         (are-equal 1 (coef-02 4 4))
         (are-equal 1 (coef-02 5 1))
         (are-equal 4 (coef-02 5 2))
         (are-equal 6 (coef-02 5 3))
         (are-equal 4 (coef-02 5 4))
         (are-equal 1 (coef-02 5 5))
    )
)
(output-test "'coef-02' func" coef-assert-02)



; --------------------
; yet another solution
; rows and columns start with 1
(define (coef-03 row col)
    (cond ((> col row) 0)
          ((= col 1) 1)
          ((+ (coef-03 (- row 1) (- col 1)) (coef-03 (- row 1) col)))))

(define coef-assert-03
    (and (are-equal 1 (coef-03 1 1))
         (are-equal 1 (coef-03 2 1))
         (are-equal 1 (coef-03 2 2))
         (are-equal 1 (coef-03 3 1))
         (are-equal 2 (coef-03 3 2))
         (are-equal 1 (coef-03 3 3))
         (are-equal 1 (coef-03 4 1))
         (are-equal 3 (coef-03 4 2))
         (are-equal 3 (coef-03 4 3))
         (are-equal 1 (coef-03 4 4))
         (are-equal 1 (coef-03 5 1))
         (are-equal 4 (coef-03 5 2))
         (are-equal 6 (coef-03 5 3))
         (are-equal 4 (coef-03 5 4))
         (are-equal 1 (coef-03 5 5))
    )
)
(output-test "'coef-03' func" coef-assert-03)



; --------------------
; yet another solution
; rows and columns start with 1
; (the first condition: `(or (< row col) (< col 1))`
;  will never be fulfilled for valid indices)
(define (coef-04 row col)
    (cond ((or (< row col) (< col 1)) 0)
          ((or (= col 1) (= col row)) 1)
          (else (+ (coef-04 (- row 1) (- col 1))
                   (coef-04 (- row 1) col)))))

(define coef-assert-04
    (and (are-equal 1 (coef-04 1 1))
         (are-equal 1 (coef-04 2 1))
         (are-equal 1 (coef-04 2 2))
         (are-equal 1 (coef-04 3 1))
         (are-equal 2 (coef-04 3 2))
         (are-equal 1 (coef-04 3 3))
         (are-equal 1 (coef-04 4 1))
         (are-equal 3 (coef-04 4 2))
         (are-equal 3 (coef-04 4 3))
         (are-equal 1 (coef-04 4 4))
         (are-equal 1 (coef-04 5 1))
         (are-equal 4 (coef-04 5 2))
         (are-equal 6 (coef-04 5 3))
         (are-equal 4 (coef-04 5 4))
    ))
(output-test "'coef-04' func" coef-assert-04)



; --------------------
; yet another solution
; rows and columns start with 1
; (the same as `coef-02`)
(define (coef-05 row col)
    (cond ((= col 1) 1)
          ((= col row) 1)
          (else (+ (coef-05 (- row 1) (- col 1))
                   (coef-05 (- row 1) col)))))

(define coef-assert-05
    (and (are-equal 1 (coef-05 1 1))
         (are-equal 1 (coef-05 2 1))
         (are-equal 1 (coef-05 2 2))
         (are-equal 1 (coef-05 3 1))
         (are-equal 2 (coef-05 3 2))
         (are-equal 1 (coef-05 3 3))
         (are-equal 1 (coef-05 4 1))
         (are-equal 3 (coef-05 4 2))
         (are-equal 3 (coef-05 4 3))
         (are-equal 1 (coef-05 4 4))
         (are-equal 1 (coef-05 5 1))
         (are-equal 4 (coef-05 5 2))
         (are-equal 6 (coef-05 5 3))
         (are-equal 4 (coef-05 5 4))
    ))
(output-test "'coef-05' func" coef-assert-05)
