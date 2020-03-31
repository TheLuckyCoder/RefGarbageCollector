#pragma once

#include "page.h"

namespace gc
{
	void start();

	/**
	 * Forces the GC to run
	 */
	void force_run();

	bool is_paused() noexcept;

	/**
	 * Pauses future runs of the GC
	 *
	 * The GC won't force_run again until it is resumed
	 */
	void pause() noexcept;

	/**
	 * Resumes future runs of the GC
	 */
	void resume() noexcept;

	/**
	 * @returns a garbage collector managed pointer
	 * In order to use this pointer pointer::init has to be called
	 */
	pointer &new_pointer();

	/**
	 * Stops the Garbage Collector Thread and frees up all the allocated objects
	 *
	 * This should only be called at the end of a program
	 * or when the GC and the objects allocated with it
	 * are no longer needed
	 */
	void shutdown();
};
