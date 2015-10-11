#ifndef ORXTEMPLATE_H_
#define ORXTEMPLATE_H_


//! Includes
// The following define skips compilation of ScrollEd (map editor) for now
#define __NO_SCROLLED__
#include <Scroll.h>

//! OrxScroll class
class OrxTemplate : public Scroll<OrxTemplate>
{
public:
	OrxTemplate();

private:
    //! Initialize the program
    virtual orxSTATUS Init ();
    //! Callback called every frame
    virtual orxSTATUS Run ();
    //! Exit the program
    virtual void      Exit ();

    virtual void      Update(const orxCLOCK_INFO &_rstInfo);

    virtual void BindObjects ();

};


#endif /* ORXTEMPLATE_H_ */
