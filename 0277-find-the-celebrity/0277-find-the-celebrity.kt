/* The knows API is defined in the parent class Relation.
      fun knows(a: Int, b: Int) : Boolean {} */

class Solution: Relation() {
    override fun findCelebrity(n: Int) : Int {
        var cand = 0
        for(i in 1..<n) {
            if(knows(cand, i)) {
                cand = i
            }
        }
        for(i in 0..<n) {
            if(cand == i) {
                continue
            }
            if(knows(cand, i) or !knows(i, cand)) {
                return -1
            }
        }
        return cand
	}
}