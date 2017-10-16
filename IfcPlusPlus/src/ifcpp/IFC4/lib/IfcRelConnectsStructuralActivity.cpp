/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/model/IfcPPGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcRelConnectsStructuralActivity.h"
#include "ifcpp/IFC4/include/IfcStructuralActivity.h"
#include "ifcpp/IFC4/include/IfcStructuralActivityAssignmentSelect.h"
#include "ifcpp/IFC4/include/IfcStructuralItem.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcRelConnectsStructuralActivity 
IfcRelConnectsStructuralActivity::IfcRelConnectsStructuralActivity() {}
IfcRelConnectsStructuralActivity::IfcRelConnectsStructuralActivity( int id ) { m_id = id; }
IfcRelConnectsStructuralActivity::~IfcRelConnectsStructuralActivity() {}
shared_ptr<IfcPPObject> IfcRelConnectsStructuralActivity::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcRelConnectsStructuralActivity> copy_self( new IfcRelConnectsStructuralActivity() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = shared_ptr<IfcGloballyUniqueId>(new IfcGloballyUniqueId( createGUID32_wstr().c_str() ) ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_RelatingElement ) { copy_self->m_RelatingElement = dynamic_pointer_cast<IfcStructuralActivityAssignmentSelect>( m_RelatingElement->getDeepCopy(options) ); }
	if( m_RelatedStructuralActivity ) { copy_self->m_RelatedStructuralActivity = dynamic_pointer_cast<IfcStructuralActivity>( m_RelatedStructuralActivity->getDeepCopy(options) ); }
	return copy_self;
}
void IfcRelConnectsStructuralActivity::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCRELCONNECTSSTRUCTURALACTIVITY" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_RelatingElement ) { m_RelatingElement->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_RelatedStructuralActivity ) { stream << "#" << m_RelatedStructuralActivity->m_id; } else { stream << "$"; }
	stream << ");";
}
void IfcRelConnectsStructuralActivity::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
const std::wstring IfcRelConnectsStructuralActivity::toString() const { return L"IfcRelConnectsStructuralActivity"; }
void IfcRelConnectsStructuralActivity::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelConnectsStructuralActivity, expecting 6, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	m_RelatingElement = IfcStructuralActivityAssignmentSelect::createObjectFromSTEP( args[4], map );
	readEntityReference( args[5], m_RelatedStructuralActivity, map );
}
void IfcRelConnectsStructuralActivity::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcRelConnects::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "RelatingElement", m_RelatingElement ) );
	vec_attributes.push_back( std::make_pair( "RelatedStructuralActivity", m_RelatedStructuralActivity ) );
}
void IfcRelConnectsStructuralActivity::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcRelConnects::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelConnectsStructuralActivity::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcRelConnects::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelConnectsStructuralActivity> ptr_self = dynamic_pointer_cast<IfcRelConnectsStructuralActivity>( ptr_self_entity );
	if( !ptr_self ) { throw IfcPPException( "IfcRelConnectsStructuralActivity::setInverseCounterparts: type mismatch" ); }
	if( m_RelatedStructuralActivity )
	{
		m_RelatedStructuralActivity->m_AssignedToStructuralItem_inverse.push_back( ptr_self );
	}
	shared_ptr<IfcStructuralItem>  RelatingElement_IfcStructuralItem = dynamic_pointer_cast<IfcStructuralItem>( m_RelatingElement );
	if( RelatingElement_IfcStructuralItem )
	{
		RelatingElement_IfcStructuralItem->m_AssignedStructuralActivity_inverse.push_back( ptr_self );
	}
}
void IfcRelConnectsStructuralActivity::unlinkFromInverseCounterparts()
{
	IfcRelConnects::unlinkFromInverseCounterparts();
	if( m_RelatedStructuralActivity )
	{
		std::vector<weak_ptr<IfcRelConnectsStructuralActivity> >& AssignedToStructuralItem_inverse = m_RelatedStructuralActivity->m_AssignedToStructuralItem_inverse;
		for( auto it_AssignedToStructuralItem_inverse = AssignedToStructuralItem_inverse.begin(); it_AssignedToStructuralItem_inverse != AssignedToStructuralItem_inverse.end(); )
		{
			shared_ptr<IfcRelConnectsStructuralActivity> self_candidate( *it_AssignedToStructuralItem_inverse );
			if( self_candidate.get() == this )
			{
				it_AssignedToStructuralItem_inverse= AssignedToStructuralItem_inverse.erase( it_AssignedToStructuralItem_inverse );
			}
			else
			{
				++it_AssignedToStructuralItem_inverse;
			}
		}
	}
	shared_ptr<IfcStructuralItem>  RelatingElement_IfcStructuralItem = dynamic_pointer_cast<IfcStructuralItem>( m_RelatingElement );
	if( RelatingElement_IfcStructuralItem )
	{
		std::vector<weak_ptr<IfcRelConnectsStructuralActivity> >& AssignedStructuralActivity_inverse = RelatingElement_IfcStructuralItem->m_AssignedStructuralActivity_inverse;
		for( auto it_AssignedStructuralActivity_inverse = AssignedStructuralActivity_inverse.begin(); it_AssignedStructuralActivity_inverse != AssignedStructuralActivity_inverse.end(); )
		{
			shared_ptr<IfcRelConnectsStructuralActivity> self_candidate( *it_AssignedStructuralActivity_inverse );
			if( self_candidate.get() == this )
			{
				it_AssignedStructuralActivity_inverse= AssignedStructuralActivity_inverse.erase( it_AssignedStructuralActivity_inverse );
			}
			else
			{
				++it_AssignedStructuralActivity_inverse;
			}
		}
	}
}