public class Slug extends BaseSlug {

    public Slug(String name) {
	super(name);
    }

    /**
     * The slug race program calls this method every turn. Your job is
     * to decide which action your slug should take by returning one
     * of the following values:
     *
     *  * Decision.MOVE: Your slug keeps on going, but this spends
     *    some energy and also makes your slug hungry.
     *
     *  * Decision.REST: Slug takes a nap. When it wakes up it has
     *    full energy, but it didn't move for a while.
     *
     *  * Decision.EAT: Your slug eats some food instead of resting
     *    or moving. This improves the slug's hunger situation.
     */
    public Decision next_round() {
	// change this to return something sensible based on
	// getHunger() and getEnergy(). Read the source code for
	// BaseSlug to see available methods.
	return Decision.MOVE;
    }
}



