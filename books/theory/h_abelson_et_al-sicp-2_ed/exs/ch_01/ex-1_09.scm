; Each of the following two procedures defines 
; a method for adding two positive integers in terms of the
; procedures `inc`, which increments its argument by 1, and
; `dec`, which decrements its argument by 1.
;
; (define (+ a b)
;     (if (= a 0) b (inc (+ dec a) b)))
; (define (+ a b)
;     (if (= a 0) b (+ (dec a) (inc b))))
;
; Using the substitution model, illustarte the process gener-
; ated by each procecure in evaluating `(+ 4 5)`. Are these
; processes iterative or recursive?


; -------------
; [solution] =>
(define (inc a) (+ a 1))
(define (dec a) (- a 1))

(define (plus1 a b)
    (if (= a 0) b (inc (plus1 (dec a) b))))
(display (plus1 4 5)) (newline)

(define (plus2 a b)
    (if (= a 0) b (plus2 (dec a) (inc b))))
(display (plus2 4 5)) (newline)


; the "plus1" procedure process:
; (plus1 4 5)
; (inc (plus1 3 5))
; (inc (inc (plus1 2 5)))
; (inc (inc (inc (plus1 1 5))))
; (inc (inc (inc (inc (plus1 0 5)))))
; (inc (inc (inc (inc 5))))
; 9

; the "plus2" procedure process:
; (plus2 4 5)
; (plus2 3 6)
; (plus2 2 7)
; (plus2 1 8)
; (plus2 0 9)
; 9

; it's not hard to see that
; the "plus1" process is recursive and
; the "plus2" process is iterative
