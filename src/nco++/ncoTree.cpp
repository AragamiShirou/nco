/* $ANTLR 2.7.6 (20071205): "ncoGrammer.g" -> "ncoTree.cpp"$ */
#include "ncoTree.hpp"
#include <antlr/Token.hpp>
#include <antlr/AST.hpp>
#include <antlr/NoViableAltException.hpp>
#include <antlr/MismatchedTokenException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/BitSet.hpp>
#line 1 "ncoGrammer.g"
#line 11 "ncoTree.cpp"
ncoTree::ncoTree()
	: ANTLR_USE_NAMESPACE(antlr)TreeParser() {
}

int  ncoTree::lmt_peek(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 967 "ncoGrammer.g"
	int nbr_dmn=0;
#line 19 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt_peek_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		lmt = _t;
		match(_t,LMT_LIST);
		_t = _t->getNextSibling();
		if ( inputState->guessing==0 ) {
#line 969 "ncoGrammer.g"
			
			RefAST aRef;     
			aRef=lmt->getFirstChild();
			nbr_dmn=0;
			while(aRef) {
			if(aRef->getType() == LMT) nbr_dmn++;    
			aRef=aRef->getNextSibling();     
			}   
			
#line 38 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return nbr_dmn;
}

int  ncoTree::statements(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 982 "ncoGrammer.g"
	int iret=0;
#line 57 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST statements_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST blk = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST exp = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST ass = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST fss = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST stmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST stmt3 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST lgcl = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST stmt1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST e1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST e2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST e3 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST stmt2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST def = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST pvid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST patt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST pstr = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 982 "ncoGrammer.g"
	
	var_sct *var;
	const std::string fnc_nm("statements");
	// list of while/for loops entered n.b depth is lpp_vtr.size()
	// Temporary fix so call run_exe only does a single parse in the
	// nested block
	static std::vector<std::string> lpp_vtr;
	
#line 84 "ncoTree.cpp"
	
	try {      // for error handling
		if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = ASTNULL;
		switch ( _t->getType()) {
		case BLOCK:
		{
			blk = _t;
			match(_t,BLOCK);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 991 "ncoGrammer.g"
				
				//cout <<"Num of Children in block="<<blk->getNumberOfChildren()<<endl;
				iret=run_exe(blk->getFirstChild(),lpp_vtr.size() );
				
				
#line 102 "ncoTree.cpp"
			}
			break;
		}
		case EXPR:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t207 = _t;
			exp = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
			match(_t,EXPR);
			_t = _t->getFirstChild();
			ass = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t207;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 997 "ncoGrammer.g"
				
				RefAST tr;
				RefAST ntr;  
				
				if(ass->getType()==ASSIGN && !prs_arg->ntl_scn ){
				ntr=ass->getFirstChild();
				if(ntr->getType()==UTIMES) 
				ntr=ntr->getFirstChild();
				
				if(ntr->getType() == VAR_ID || ntr->getType() ==ATT_ID){
				ntr->addChild( astFactory->create(NORET,"no_ret") );
				// std::cout << "Modified assign "<<exp->toStringTree()<<std::endl;      
				}
				} 
				
				
				var=out(exp->getFirstChild());
				if(var != (var_sct*)NULL)
				var=nco_var_free(var);
				iret=EXPR;
				
#line 140 "ncoTree.cpp"
			}
			break;
		}
		case FEXPR:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t208 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp114_AST_in = _t;
			match(_t,FEXPR);
			_t = _t->getFirstChild();
			fss = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t208;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1022 "ncoGrammer.g"
				
				
				var=out(fss);
				if(var != (var_sct*)NULL)
				var=nco_var_free(var);
				iret=FEXPR;
				
#line 164 "ncoTree.cpp"
			}
			break;
		}
		case IF:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t209 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp115_AST_in = _t;
			match(_t,IF);
			_t = _t->getFirstChild();
			var=out(_t);
			_t = _retTree;
			stmt = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t209;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1030 "ncoGrammer.g"
				
				//if can have only 3 or 4 parts  , 1 node and 2 or 3 siblings
				// IF LOGICAL_EXP STATEMENT1 STATEMENT2
				bool br;
					  //Calculate logical expression
					  br=ncap_var_lgcl(var);
					  var=nco_var_free(var);
				
				if(br){ 
				// Execute 2nd sibling  
				if(stmt->getType()==BLOCK)
				iret=run_exe(stmt,lpp_vtr.size());
				else
				iret=statements(stmt);     
				}
				
				// See if else stmt exists (3rd sibling)       
					  if(!br && (stmt=stmt->getNextSibling()) ){
				if(stmt->getType()==BLOCK)
				iret=run_exe(stmt,lpp_vtr.size());
				else
				iret=statements(stmt);     
				
				}
				
				var=NULL_CEWI;
				
				
#line 211 "ncoTree.cpp"
			}
			break;
		}
		case WHERE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t210 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp116_AST_in = _t;
			match(_t,WHERE);
			_t = _t->getFirstChild();
			var=out(_t);
			_t = _retTree;
			stmt3 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t210;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1059 "ncoGrammer.g"
				
				// convert mask to short 
				RefAST tr; 
				var=nco_var_cnf_typ(NC_SHORT,var);
				
				//change missing values to zero
				if(var->has_mss_val){
				var=ncap_var_var_stc(var,NULL_CEWI,MISS2ZERO);
				var->has_mss_val=False;
				var->mss_val.vp=(void*)nco_free(var->mss_val.vp);
				}         
				
				//deal with block
				if(stmt3->getType()==BLOCK){
				tr=stmt3->getFirstChild();
				while(tr) {
				(void)where_assign(tr,var);       
				tr=tr->getNextSibling();
				} 
				} else 
				where_assign(stmt3,var);
				
				// deal with else-where
				if(tr=stmt3->getNextSibling()) {
				
				//invert mask
				var=ncap_var_var_stc(var,NULL_CEWI,LNOT); 
				
				if(tr->getType()==BLOCK){
				tr=tr->getFirstChild();
				while(tr) {
				(void)where_assign(tr,var);       
				tr=tr->getNextSibling();
				} 
				} else 
				where_assign(tr,var);
				
				}
				
				if(var != (var_sct*)NULL)
				var=nco_var_free(var);
				iret=WHERE;      
				
#line 273 "ncoTree.cpp"
			}
			break;
		}
		case WHILE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t211 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp117_AST_in = _t;
			match(_t,WHILE);
			_t = _t->getFirstChild();
			lgcl = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			stmt1 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t211;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1103 "ncoGrammer.g"
				
				
				bool br;
				var_sct *var_tf;  
				
				var_tf=out(lgcl);
				br=ncap_var_lgcl(var_tf);
				var_tf=nco_var_free(var_tf);
				
				lpp_vtr.push_back("while");
				
				while(br){ 
				if(stmt1->getType()==BLOCK)
				iret=run_exe(stmt1,lpp_vtr.size());
				else
				iret=statements(stmt1);     
				
				if(iret==BREAK) break;
				var_tf=out(lgcl);
				br=ncap_var_lgcl(var_tf); 
				var_tf=nco_var_free(var_tf);       
				
				}
				lpp_vtr.pop_back(); 
				iret=WHILE;
				var=NULL_CEWI; 
				
				
#line 321 "ncoTree.cpp"
			}
			break;
		}
		case FOR:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t212 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp118_AST_in = _t;
			match(_t,FOR);
			_t = _t->getFirstChild();
			e1 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			e2 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			e3 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			stmt2 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t212;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1132 "ncoGrammer.g"
				
				bool b1,b2,b3,br;
				var_sct *var_f1;
				var_sct *var_f2;
				var_sct *var_f3;
				
				b1=(e1->getType()!=NULL_NODE ? true:false);
				b2=(e2->getType()!=NULL_NODE ? true:false);
				b3=(e3->getType()!=NULL_NODE ? true:false);
				
				lpp_vtr.push_back("for");
				
				if(b1){
				var_f1=out(e1);
				var_f1=nco_var_free(var_f1);
				}          
				
				if(b2){
				var_f2=out(e2);
				br=ncap_var_lgcl(var_f2);
				var_f2=nco_var_free(var_f2);
				} else br=true;
				
				while(br){
				
				if(stmt2->getType()==BLOCK)
				iret=run_exe(stmt2,lpp_vtr.size());
				else
				iret=statements(stmt2);     
				
				if(iret==BREAK) break;
				
				
				if(b3){
				var_f3=out(e3);
				var_f3=nco_var_free(var_f3);
				}
				
				
				if(b2){
				var_f2=out(e2);
				br=ncap_var_lgcl(var_f2);
				var_f2=nco_var_free(var_f2);
				} 
				
				} // end while
				
				lpp_vtr.pop_back();
				iret=FOR;
				var=NULL_CEWI;                
				
				
#line 399 "ncoTree.cpp"
			}
			break;
		}
		case ELSE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp119_AST_in = _t;
			match(_t,ELSE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1186 "ncoGrammer.g"
				iret=ELSE;
#line 411 "ncoTree.cpp"
			}
			break;
		}
		case BREAK:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp120_AST_in = _t;
			match(_t,BREAK);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1187 "ncoGrammer.g"
				iret=BREAK;
#line 423 "ncoTree.cpp"
			}
			break;
		}
		case CONTINUE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp121_AST_in = _t;
			match(_t,CONTINUE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1188 "ncoGrammer.g"
				iret=CONTINUE;
#line 435 "ncoTree.cpp"
			}
			break;
		}
		case NULL_NODE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp122_AST_in = _t;
			match(_t,NULL_NODE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1189 "ncoGrammer.g"
				iret=NULL_NODE;
#line 447 "ncoTree.cpp"
			}
			break;
		}
		case DEFDIM:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t213 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp123_AST_in = _t;
			match(_t,DEFDIM);
			_t = _t->getFirstChild();
			def = _t;
			match(_t,NSTRING);
			_t = _t->getNextSibling();
			var=out(_t);
			_t = _retTree;
			_t = __t213;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1191 "ncoGrammer.g"
				
				
				long sz;
				
				var=nco_var_cnf_typ(NC_INT,var);
				iret=DEFDIM;
				
				(void)cast_void_nctype((nc_type)NC_INT,&var->val);
				sz=*var->val.lp;
				var=(var_sct*)nco_var_free(var);
				(void)ncap_def_dim(def->getText(),sz,prs_arg);
				
#line 478 "ncoTree.cpp"
			}
			break;
		}
		default:
			bool synPredMatched216 = false;
			if (((_t->getType() == PRINT))) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t216 = _t;
				synPredMatched216 = true;
				inputState->guessing++;
				try {
					{
					ANTLR_USE_NAMESPACE(antlr)RefAST __t215 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp124_AST_in = _t;
					match(_t,PRINT);
					_t = _t->getFirstChild();
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp125_AST_in = _t;
					match(_t,VAR_ID);
					_t = _t->getNextSibling();
					_t = __t215;
					_t = _t->getNextSibling();
					}
				}
				catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
					synPredMatched216 = false;
				}
				_t = __t216;
				inputState->guessing--;
			}
			if ( synPredMatched216 ) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t217 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp126_AST_in = _t;
				match(_t,PRINT);
				_t = _t->getFirstChild();
				pvid = _t;
				match(_t,VAR_ID);
				_t = _t->getNextSibling();
				_t = __t217;
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1206 "ncoGrammer.g"
					
					
					int var_id;
					int fl_id=-1;
					char *fmt_sng;
					std::string va_nm(pvid->getText());
					NcapVar *Nvar;
					
					
					if(prs_arg->ntl_scn) goto end2;
					Nvar=prs_arg->var_vtr.find(va_nm);
					
					// check output first 
					if(Nvar){
					if(Nvar->flg_mem) {
					wrn_prn(fnc_nm,"Cannot print out RAM variables at the moment!");
					goto end2;
					}
					fl_id=prs_arg->out_id;
					}else{
					// Check input file for var   
					if(NC_NOERR==nco_inq_varid_flg(prs_arg->in_id,va_nm.c_str(),&var_id))
					fl_id=prs_arg->in_id;
					}
					
					if(fl_id==-1) {
					wrn_prn(fnc_nm,"Print function cannot find var \""+va_nm+"\" in input or output");
					goto end2;
					}
					
					// Grab format string 
					if(pvid->getNextSibling() && pvid->getNextSibling()->getType()==NSTRING)
					fmt_sng=strdup(pvid->getNextSibling()->getText().c_str());
					else 
					fmt_sng=(char*)NULL; 
					
					
					
					
					if( fl_id >=0)
					(void)nco_prn_var_val_lmt(fl_id,va_nm.c_str(),(lmt_sct*)NULL,0L,fmt_sng,prs_arg->FORTRAN_IDX_CNV,False,False);
					
					
					if(fmt_sng)
					fmt_sng=(char*)nco_free(fmt_sng); 
					
					
					end2: ;
					
					
#line 569 "ncoTree.cpp"
				}
			}
			else {
				bool synPredMatched220 = false;
				if (((_t->getType() == PRINT))) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t220 = _t;
					synPredMatched220 = true;
					inputState->guessing++;
					try {
						{
						ANTLR_USE_NAMESPACE(antlr)RefAST __t219 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp127_AST_in = _t;
						match(_t,PRINT);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp128_AST_in = _t;
						match(_t,ATT_ID);
						_t = _t->getNextSibling();
						_t = __t219;
						_t = _t->getNextSibling();
						}
					}
					catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
						synPredMatched220 = false;
					}
					_t = __t220;
					inputState->guessing--;
				}
				if ( synPredMatched220 ) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t221 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp129_AST_in = _t;
					match(_t,PRINT);
					_t = _t->getFirstChild();
					patt = _t;
					match(_t,ATT_ID);
					_t = _t->getNextSibling();
					_t = __t221;
					_t = _t->getNextSibling();
					if ( inputState->guessing==0 ) {
#line 1256 "ncoGrammer.g"
						
						
						int apsn;
						var_sct *var1;
						char* fmt_sng;
						std::string fl_nm;
						std::string att_nm;
						std::string var_nm;
						NcapVar *Nvar;
						
						var=NULL_CEWI;
						
						// print only on second parse
						if(prs_arg->ntl_scn) goto end3;
						
						fl_nm=patt->getText();
						apsn=fl_nm.find("@");
						var_nm=fl_nm.substr(0,apsn);
						att_nm=fl_nm.substr(apsn+1);            
						
						Nvar=prs_arg->var_vtr.find(var_nm);
						if( Nvar && att_nm==std::string(nco_mss_val_sng_get()) ){         
						if(Nvar->var->has_mss_val==True){
						var1=ncap_sclr_var_mk(fl_nm,Nvar->var->type,true);
						(void)memcpy(var1->val.vp,Nvar->var->mss_val.vp, nco_typ_lng(Nvar->var->type));
						var=var1;
						}else{
						wrn_prn(fnc_nm,"Cannot print missing value \""+ fl_nm+ "\" for variable \""+ var_nm +"\" as it is undefined");
						goto end3;    
						}
						}else{   
						Nvar=prs_arg->var_vtr.find(fl_nm);
						if(Nvar==NULL_CEWI) 
						var=ncap_att_init(fl_nm,prs_arg);
						else
						var=nco_var_dpl(Nvar->var); 
						}
						
						if(var==NULL_CEWI ){
						wrn_prn(fnc_nm,"Cannot print  attribute \"" +fl_nm+ "\". Not present in input or output files.");
						goto end3;    
						}
						
						// Grab format string 
						if(patt->getNextSibling() && patt->getNextSibling()->getType()==NSTRING)
						fmt_sng=strdup(patt->getNextSibling()->getText().c_str());
						else 
						fmt_sng=(char*)NULL; 
						
						(void)ncap_att_prn(var,fmt_sng,prs_arg);
						var=nco_var_free(var); 
						
						end3:   ;
						
#line 663 "ncoTree.cpp"
					}
				}
				else {
					bool synPredMatched224 = false;
					if (((_t->getType() == PRINT))) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t224 = _t;
						synPredMatched224 = true;
						inputState->guessing++;
						try {
							{
							ANTLR_USE_NAMESPACE(antlr)RefAST __t223 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp130_AST_in = _t;
							match(_t,PRINT);
							_t = _t->getFirstChild();
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp131_AST_in = _t;
							match(_t,NSTRING);
							_t = _t->getNextSibling();
							_t = __t223;
							_t = _t->getNextSibling();
							}
						}
						catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
							synPredMatched224 = false;
						}
						_t = __t224;
						inputState->guessing--;
					}
					if ( synPredMatched224 ) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t225 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp132_AST_in = _t;
						match(_t,PRINT);
						_t = _t->getFirstChild();
						pstr = _t;
						match(_t,NSTRING);
						_t = _t->getNextSibling();
						_t = __t225;
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1311 "ncoGrammer.g"
							
							char *prn_sng;
							
							if(!prs_arg->ntl_scn){
							prn_sng=strdup(pstr->getText().c_str());
							(void)sng_ascii_trn(prn_sng);            
							
							fprintf(stdout,prn_sng);
							prn_sng=(char*)nco_free(prn_sng);
							}    
							
#line 714 "ncoTree.cpp"
						}
					}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}}}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return iret;
}

var_sct * ncoTree::out(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 1883 "ncoGrammer.g"
	var_sct *var;
#line 738 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST out_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST pls_asn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST min_asn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tim_asn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST div_asn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST asn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST wasn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST qus = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST m = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST args = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST mtd = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST mfnc = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST margs = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST dval = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST v = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vlst = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST str = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_float = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_double = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_int = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_short = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_byte = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_ubyte = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_ushort = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_uint = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_int64 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_uint64 = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 1883 "ncoGrammer.g"
	
	const std::string fnc_nm("out"); 
		var_sct *var1;
	var_sct *var2;
	var=NULL_CEWI;
	
#line 775 "ncoTree.cpp"
	
	try {      // for error handling
		if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = ASTNULL;
		switch ( _t->getType()) {
		case TIMES:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t293 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp133_AST_in = _t;
			match(_t,TIMES);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t293;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1910 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, TIMES );
#line 796 "ncoTree.cpp"
			}
			break;
		}
		case DIVIDE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t294 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp134_AST_in = _t;
			match(_t,DIVIDE);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t294;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1913 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, DIVIDE );
#line 815 "ncoTree.cpp"
			}
			break;
		}
		case MOD:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t295 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp135_AST_in = _t;
			match(_t,MOD);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t295;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1915 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, MOD);
#line 834 "ncoTree.cpp"
			}
			break;
		}
		case CARET:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t296 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp136_AST_in = _t;
			match(_t,CARET);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t296;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1917 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, CARET);
#line 853 "ncoTree.cpp"
			}
			break;
		}
		case LNOT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t297 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp137_AST_in = _t;
			match(_t,LNOT);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			_t = __t297;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1921 "ncoGrammer.g"
				var=ncap_var_var_op(var1,NULL_CEWI, LNOT );
#line 870 "ncoTree.cpp"
			}
			break;
		}
		case INC:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t300 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp138_AST_in = _t;
			match(_t,INC);
			_t = _t->getFirstChild();
			var1=out_asn(_t);
			_t = _retTree;
			_t = __t300;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1927 "ncoGrammer.g"
				var=ncap_var_var_inc(var1,NULL_CEWI,INC,false,prs_arg);
#line 887 "ncoTree.cpp"
			}
			break;
		}
		case DEC:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t301 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp139_AST_in = _t;
			match(_t,DEC);
			_t = _t->getFirstChild();
			var1=out_asn(_t);
			_t = _retTree;
			_t = __t301;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1929 "ncoGrammer.g"
				var=ncap_var_var_inc(var1,NULL_CEWI, DEC,false,prs_arg );
#line 904 "ncoTree.cpp"
			}
			break;
		}
		case POST_INC:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t302 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp140_AST_in = _t;
			match(_t,POST_INC);
			_t = _t->getFirstChild();
			var1=out_asn(_t);
			_t = _retTree;
			_t = __t302;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1931 "ncoGrammer.g"
				
				var=ncap_var_var_inc(var1,NULL_CEWI,POST_INC,false,prs_arg);
				
#line 923 "ncoTree.cpp"
			}
			break;
		}
		case POST_DEC:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t303 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp141_AST_in = _t;
			match(_t,POST_DEC);
			_t = _t->getFirstChild();
			var1=out_asn(_t);
			_t = _retTree;
			_t = __t303;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1934 "ncoGrammer.g"
				
				var=ncap_var_var_inc(var1,NULL_CEWI,POST_DEC,false,prs_arg);
				
#line 942 "ncoTree.cpp"
			}
			break;
		}
		case LAND:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t304 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp142_AST_in = _t;
			match(_t,LAND);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t304;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1940 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, LAND );
#line 961 "ncoTree.cpp"
			}
			break;
		}
		case LOR:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t305 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp143_AST_in = _t;
			match(_t,LOR);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t305;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1942 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, LOR );
#line 980 "ncoTree.cpp"
			}
			break;
		}
		case LTHAN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t306 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp144_AST_in = _t;
			match(_t,LTHAN);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t306;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1945 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, LTHAN );
#line 999 "ncoTree.cpp"
			}
			break;
		}
		case GTHAN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t307 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp145_AST_in = _t;
			match(_t,GTHAN);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t307;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1947 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, GTHAN );
#line 1018 "ncoTree.cpp"
			}
			break;
		}
		case GEQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t308 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp146_AST_in = _t;
			match(_t,GEQ);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t308;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1949 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, GEQ );
#line 1037 "ncoTree.cpp"
			}
			break;
		}
		case LEQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t309 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp147_AST_in = _t;
			match(_t,LEQ);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t309;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1951 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, LEQ );
#line 1056 "ncoTree.cpp"
			}
			break;
		}
		case EQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t310 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp148_AST_in = _t;
			match(_t,EQ);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t310;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1953 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, EQ );
#line 1075 "ncoTree.cpp"
			}
			break;
		}
		case NEQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t311 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp149_AST_in = _t;
			match(_t,NEQ);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t311;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1955 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, NEQ );
#line 1094 "ncoTree.cpp"
			}
			break;
		}
		case FLTHAN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t312 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp150_AST_in = _t;
			match(_t,FLTHAN);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t312;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1959 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, FLTHAN );
#line 1113 "ncoTree.cpp"
			}
			break;
		}
		case FGTHAN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t313 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp151_AST_in = _t;
			match(_t,FGTHAN);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t313;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1961 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, FGTHAN );
#line 1132 "ncoTree.cpp"
			}
			break;
		}
		case PLUS_ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t314 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp152_AST_in = _t;
			match(_t,PLUS_ASSIGN);
			_t = _t->getFirstChild();
			pls_asn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			var2=out(_t);
			_t = _retTree;
			_t = __t314;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1964 "ncoGrammer.g"
				
				var1=out_asn(pls_asn);
				var=ncap_var_var_inc(var1,var2, PLUS_ASSIGN ,(pls_asn->getType()==UTIMES), prs_arg);
				
#line 1155 "ncoTree.cpp"
			}
			break;
		}
		case MINUS_ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t315 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp153_AST_in = _t;
			match(_t,MINUS_ASSIGN);
			_t = _t->getFirstChild();
			min_asn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			var2=out(_t);
			_t = _retTree;
			_t = __t315;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1968 "ncoGrammer.g"
				
				var1=out_asn(min_asn);
				var=ncap_var_var_inc(var1,var2, MINUS_ASSIGN ,(min_asn->getType()==UTIMES), prs_arg);
				
#line 1178 "ncoTree.cpp"
			}
			break;
		}
		case TIMES_ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t316 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp154_AST_in = _t;
			match(_t,TIMES_ASSIGN);
			_t = _t->getFirstChild();
			tim_asn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			var2=out(_t);
			_t = _retTree;
			_t = __t316;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1972 "ncoGrammer.g"
				
				var1=out_asn(tim_asn);
				var=ncap_var_var_inc(var1,var2, TIMES_ASSIGN ,(tim_asn->getType()==UTIMES), prs_arg);
				
#line 1201 "ncoTree.cpp"
			}
			break;
		}
		case DIVIDE_ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t317 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp155_AST_in = _t;
			match(_t,DIVIDE_ASSIGN);
			_t = _t->getFirstChild();
			div_asn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			var2=out(_t);
			_t = _retTree;
			_t = __t317;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1976 "ncoGrammer.g"
					
				var1=out_asn(div_asn);
				var=ncap_var_var_inc(var1,var2, DIVIDE_ASSIGN ,(div_asn->getType()==UTIMES), prs_arg);
				
#line 1224 "ncoTree.cpp"
			}
			break;
		}
		case ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t318 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp156_AST_in = _t;
			match(_t,ASSIGN);
			_t = _t->getFirstChild();
			asn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t318;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1982 "ncoGrammer.g"
				
				// Check for RAM variable - if present 
				// change tree - for example from:
				//     ( EXPR ( = ( * n1 ) ( + four four ) ) )
				// to  ( EXPR ( = n1 ( + four four ) ) )
				RefAST tr;
				bool bram;
				NcapVar *Nvar;
				
				if(asn->getType()==UTIMES){
				tr=asn->getFirstChild();
				tr->setNextSibling(asn->getNextSibling());
				bram=true;
				} else { 
				tr=asn; 
				bram=false;
				}
				
				// Die if attempting to create a RAM var 
				// from an existing disk var   
				Nvar= prs_arg->var_vtr.find(tr->getText());
				
				if(bram && tr->getType()==VAR_ID && Nvar && Nvar->flg_mem==false){
				std::string serr;
				serr= "It is impossible to recast disk variable: \"" + tr->getText() +"\" as a RAM variable.";
				err_prn(fnc_nm,serr );       
				}                
				
				
				
				if(prs_arg->ntl_scn)
				var=assign_ntl(tr,bram); 
				else
				var=assign(tr,bram);
				
				
#line 1277 "ncoTree.cpp"
			}
			break;
		}
		case WHERE_ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t319 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp157_AST_in = _t;
			match(_t,WHERE_ASSIGN);
			_t = _t->getFirstChild();
			wasn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t319;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2018 "ncoGrammer.g"
				
				
				
				
#line 1298 "ncoTree.cpp"
			}
			break;
		}
		case QUESTION:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t320 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp158_AST_in = _t;
			match(_t,QUESTION);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			qus = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t320;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2024 "ncoGrammer.g"
				
				bool br;
				
				// if initial scan 
				if(prs_arg->ntl_scn){
				var=ncap_var_udf("~question"); 
				} else {
				
				br=ncap_var_lgcl(var1);
				if(br) 
				var=out(qus);
				else
				var=out(qus->getNextSibling());      
				}   
				var1=nco_var_free(var1);
				
#line 1333 "ncoTree.cpp"
			}
			break;
		}
		case FUNC:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t321 = _t;
			m = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
			match(_t,FUNC);
			_t = _t->getFirstChild();
			args = _t;
			match(_t,FUNC_ARG);
			_t = _t->getNextSibling();
			_t = __t321;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2043 "ncoGrammer.g"
				
				RefAST tr;
				std::string sfnm(m->getText());
				std::vector<fmc_cls>::iterator we=std::lower_bound(prs_arg->fmc_vtr.begin(),prs_arg->fmc_vtr.end(),fmc_cls(sfnm));
				// see if string found
				if( we->fnm() == sfnm){
				//Call function
				var=we->vfnc()->fnd(tr ,args, *we,*this); 
				} else { 
				cout << "Function  " << sfnm << " not found" << endl;
				exit(1);
				}
				
#line 1363 "ncoTree.cpp"
			}
			break;
		}
		case DOT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t322 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp159_AST_in = _t;
			match(_t,DOT);
			_t = _t->getFirstChild();
			mtd = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			mfnc = _t;
			match(_t,FUNC);
			_t = _t->getNextSibling();
			margs = _t;
			match(_t,FUNC_ARG);
			_t = _t->getNextSibling();
			_t = __t322;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2058 "ncoGrammer.g"
				
				std::string sfnm(mfnc->getText());
				std::vector<fmc_cls>::iterator we=std::lower_bound(prs_arg->fmc_vtr.begin(),prs_arg->fmc_vtr.end(),fmc_cls(sfnm));
				// see if string found
				if( we->fnm() == sfnm){
				//Call function
				var=we->vfnc()->fnd(mtd ,margs, *we,*this); 
				} else { 
				cout << "Method  " << sfnm << " not found" << endl;
				exit(1);
				}
				
#line 1398 "ncoTree.cpp"
			}
			break;
		}
		case DIM_ID_SIZE:
		{
			dval = _t;
			match(_t,DIM_ID_SIZE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2072 "ncoGrammer.g"
				
				string sDim=dval->getText();
				dmn_sct *dmn_fd;
				
				// Check output
				if(prs_arg->ntl_scn){
				var=ncap_sclr_var_mk(static_cast<std::string>("~dmn"),(nc_type)NC_INT,false);
				}else{ 
				// Check output 
				dmn_fd=prs_arg->dmn_out_vtr.find(sDim);
				// Check input
				if(dmn_fd==NULL_CEWI)
				dmn_fd=prs_arg->dmn_in_vtr.find(sDim);
				
				if( dmn_fd==NULL_CEWI ){
				err_prn(fnc_nm,"Unable to locate dimension " +dval->getText()+ " in input or output files ");
				}
				var=ncap_sclr_var_mk(static_cast<std::string>("~dmn"),dmn_fd->sz);
				} // end else 
				
#line 1429 "ncoTree.cpp"
			}
			break;
		}
		case ATT_ID:
		{
			att = _t;
			match(_t,ATT_ID);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2120 "ncoGrammer.g"
				
				
				NcapVar *Nvar=NULL;
				
				if(prs_arg->ntl_scn)
				Nvar=prs_arg->int_vtr.find(att->getText());
				
				if(Nvar==NULL) 
				Nvar=prs_arg->var_vtr.find(att->getText());
				
				var=NULL_CEWI;    
				if(Nvar !=NULL)
				var=nco_var_dpl(Nvar->var);
				else    
				// Check input file for attribute
				var=ncap_att_init(att->getText(),prs_arg);
				
				if(!prs_arg->ntl_scn && var==NULL_CEWI ){
				err_prn(fnc_nm,"Unable to locate attribute " +att->getText()+ " in input or output files.");
				}
				
				// if att not found return undefined
				if(prs_arg->ntl_scn && var==NULL_CEWI )
				var=ncap_var_udf(att->getText().c_str());
				
				
				if(prs_arg->ntl_scn && var->val.vp !=NULL)
				var->val.vp=(void*)nco_free(var->val.vp);
				
				
#line 1470 "ncoTree.cpp"
			}
			break;
		}
		case VALUE_LIST:
		{
			vlst = _t;
			match(_t,VALUE_LIST);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2152 "ncoGrammer.g"
				
				var=value_list(vlst);
				
#line 1484 "ncoTree.cpp"
			}
			break;
		}
		case NSTRING:
		{
			str = _t;
			match(_t,NSTRING);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2157 "ncoGrammer.g"
				
				char *tsng;
				
				tsng=strdup(str->getText().c_str());
				(void)sng_ascii_trn(tsng);            
				var=(var_sct *)nco_malloc(sizeof(var_sct));
				/* Set defaults */
				(void)var_dfl_set(var); 
				/* Overwrite with attribute expression information */
				var->nm=strdup("~zz@string");
				var->nbr_dim=0;
				var->sz=strlen(tsng);
				var->type=NC_CHAR;
				if(!prs_arg->ntl_scn){
				var->val.vp=(void*)nco_malloc(var->sz*nco_typ_lng(NC_CHAR));
				(void)cast_void_nctype((nc_type)NC_CHAR,&var->val);
				strncpy(var->val.cp,tsng,(size_t)var->sz);  
				(void)cast_nctype_void((nc_type)NC_CHAR,&var->val);
				}
				tsng=(char*)nco_free(tsng);      
				
#line 1516 "ncoTree.cpp"
			}
			break;
		}
		case FLOAT:
		{
			val_float = _t;
			match(_t,FLOAT);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2181 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~float"),(nc_type)NC_FLOAT,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~float"),static_cast<float>(std::strtod(val_float->getText().c_str(),(char **)NULL)));
#line 1528 "ncoTree.cpp"
			}
			break;
		}
		case DOUBLE:
		{
			val_double = _t;
			match(_t,DOUBLE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2183 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~double"),(nc_type)NC_DOUBLE,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~double"),strtod(val_double->getText().c_str(),(char **)NULL));
#line 1540 "ncoTree.cpp"
			}
			break;
		}
		case INT:
		{
			val_int = _t;
			match(_t,INT);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2185 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~int"),(nc_type)NC_INT,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~int"),static_cast<nco_int>(std::strtol(val_int->getText().c_str(),(char **)NULL,10)));
#line 1552 "ncoTree.cpp"
			}
			break;
		}
		case SHORT:
		{
			val_short = _t;
			match(_t,SHORT);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2187 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~short"),(nc_type)NC_SHORT,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~short"),static_cast<nco_short>(std::strtol(val_short->getText().c_str(),(char **)NULL,10)));
#line 1564 "ncoTree.cpp"
			}
			break;
		}
		case BYTE:
		{
			val_byte = _t;
			match(_t,BYTE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2189 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~byte"),(nc_type)NC_BYTE,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~byte"),static_cast<nco_byte>(std::strtol(val_byte->getText().c_str(),(char **)NULL,10)));
#line 1576 "ncoTree.cpp"
			}
			break;
		}
		case UBYTE:
		{
			val_ubyte = _t;
			match(_t,UBYTE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2194 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~ubyte"),(nc_type)NC_UBYTE,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~ubyte"),static_cast<nco_ubyte>(std::strtoul(val_ubyte->getText().c_str(),(char **)NULL,10)));
#line 1588 "ncoTree.cpp"
			}
			break;
		}
		case USHORT:
		{
			val_ushort = _t;
			match(_t,USHORT);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2198 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~ushort"),(nc_type)NC_USHORT,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~ushort"),static_cast<nco_ushort>(std::strtoul(val_ushort->getText().c_str(),(char **)NULL,10)));
#line 1600 "ncoTree.cpp"
			}
			break;
		}
		case UINT:
		{
			val_uint = _t;
			match(_t,UINT);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2200 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~uint"),(nc_type)NC_UINT,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~uint"),static_cast<nco_uint>(std::strtoul(val_uint->getText().c_str(),(char **)NULL,10)));
#line 1612 "ncoTree.cpp"
			}
			break;
		}
		case INT64:
		{
			val_int64 = _t;
			match(_t,INT64);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2202 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~int64"),(nc_type)NC_INT64,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~int64"),sng2nbr(val_int64->getText(),nco_int64_CEWI));
#line 1624 "ncoTree.cpp"
			}
			break;
		}
		case UINT64:
		{
			val_uint64 = _t;
			match(_t,UINT64);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2206 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~uint64"),(nc_type)NC_UINT64,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~uint64"),sng2nbr(val_uint64->getText(),nco_uint64_CEWI));
#line 1636 "ncoTree.cpp"
			}
			break;
		}
		default:
			bool synPredMatched263 = false;
			if (((_t->getType() == PLUS))) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t263 = _t;
				synPredMatched263 = true;
				inputState->guessing++;
				try {
					{
					ANTLR_USE_NAMESPACE(antlr)RefAST __t262 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp160_AST_in = _t;
					match(_t,PLUS);
					_t = _t->getFirstChild();
					out(_t);
					_t = _retTree;
					out(_t);
					_t = _retTree;
					_t = __t262;
					_t = _t->getNextSibling();
					}
				}
				catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
					synPredMatched263 = false;
				}
				_t = __t263;
				inputState->guessing--;
			}
			if ( synPredMatched263 ) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t264 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp161_AST_in = _t;
				match(_t,PLUS);
				_t = _t->getFirstChild();
				var1=out(_t);
				_t = _retTree;
				var2=out(_t);
				_t = _retTree;
				_t = __t264;
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1893 "ncoGrammer.g"
					var=ncap_var_var_op(var1,var2, PLUS );
#line 1680 "ncoTree.cpp"
				}
			}
			else {
				bool synPredMatched267 = false;
				if (((_t->getType() == MINUS))) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t267 = _t;
					synPredMatched267 = true;
					inputState->guessing++;
					try {
						{
						ANTLR_USE_NAMESPACE(antlr)RefAST __t266 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp162_AST_in = _t;
						match(_t,MINUS);
						_t = _t->getFirstChild();
						out(_t);
						_t = _retTree;
						out(_t);
						_t = _retTree;
						_t = __t266;
						_t = _t->getNextSibling();
						}
					}
					catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
						synPredMatched267 = false;
					}
					_t = __t267;
					inputState->guessing--;
				}
				if ( synPredMatched267 ) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t268 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp163_AST_in = _t;
					match(_t,MINUS);
					_t = _t->getFirstChild();
					var1=out(_t);
					_t = _retTree;
					var2=out(_t);
					_t = _retTree;
					_t = __t268;
					_t = _t->getNextSibling();
					if ( inputState->guessing==0 ) {
#line 1895 "ncoGrammer.g"
						var=ncap_var_var_op(var1,var2, MINUS );
#line 1723 "ncoTree.cpp"
					}
				}
				else {
					bool synPredMatched272 = false;
					if (((_t->getType() == UTIMES))) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t272 = _t;
						synPredMatched272 = true;
						inputState->guessing++;
						try {
							{
							ANTLR_USE_NAMESPACE(antlr)RefAST __t270 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp164_AST_in = _t;
							match(_t,UTIMES);
							_t = _t->getFirstChild();
							ANTLR_USE_NAMESPACE(antlr)RefAST __t271 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp165_AST_in = _t;
							match(_t,POST_INC);
							_t = _t->getFirstChild();
							out(_t);
							_t = _retTree;
							_t = __t271;
							_t = _t->getNextSibling();
							_t = __t270;
							_t = _t->getNextSibling();
							}
						}
						catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
							synPredMatched272 = false;
						}
						_t = __t272;
						inputState->guessing--;
					}
					if ( synPredMatched272 ) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t273 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp166_AST_in = _t;
						match(_t,UTIMES);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST __t274 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp167_AST_in = _t;
						match(_t,POST_INC);
						_t = _t->getFirstChild();
						var1=out_asn(_t);
						_t = _retTree;
						_t = __t274;
						_t = _t->getNextSibling();
						_t = __t273;
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1896 "ncoGrammer.g"
							
							var=ncap_var_var_inc(var1,NULL_CEWI,POST_INC,true,prs_arg);      
							
#line 1776 "ncoTree.cpp"
						}
					}
					else {
						bool synPredMatched278 = false;
						if (((_t->getType() == UTIMES))) {
							ANTLR_USE_NAMESPACE(antlr)RefAST __t278 = _t;
							synPredMatched278 = true;
							inputState->guessing++;
							try {
								{
								ANTLR_USE_NAMESPACE(antlr)RefAST __t276 = _t;
								ANTLR_USE_NAMESPACE(antlr)RefAST tmp168_AST_in = _t;
								match(_t,UTIMES);
								_t = _t->getFirstChild();
								ANTLR_USE_NAMESPACE(antlr)RefAST __t277 = _t;
								ANTLR_USE_NAMESPACE(antlr)RefAST tmp169_AST_in = _t;
								match(_t,POST_DEC);
								_t = _t->getFirstChild();
								out(_t);
								_t = _retTree;
								_t = __t277;
								_t = _t->getNextSibling();
								_t = __t276;
								_t = _t->getNextSibling();
								}
							}
							catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
								synPredMatched278 = false;
							}
							_t = __t278;
							inputState->guessing--;
						}
						if ( synPredMatched278 ) {
							ANTLR_USE_NAMESPACE(antlr)RefAST __t279 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp170_AST_in = _t;
							match(_t,UTIMES);
							_t = _t->getFirstChild();
							ANTLR_USE_NAMESPACE(antlr)RefAST __t280 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp171_AST_in = _t;
							match(_t,POST_DEC);
							_t = _t->getFirstChild();
							var1=out_asn(_t);
							_t = _retTree;
							_t = __t280;
							_t = _t->getNextSibling();
							_t = __t279;
							_t = _t->getNextSibling();
							if ( inputState->guessing==0 ) {
#line 1899 "ncoGrammer.g"
								
								var=ncap_var_var_inc(var1,NULL_CEWI,POST_DEC,true,prs_arg);      
								
#line 1829 "ncoTree.cpp"
							}
						}
						else {
							bool synPredMatched284 = false;
							if (((_t->getType() == UTIMES))) {
								ANTLR_USE_NAMESPACE(antlr)RefAST __t284 = _t;
								synPredMatched284 = true;
								inputState->guessing++;
								try {
									{
									ANTLR_USE_NAMESPACE(antlr)RefAST __t282 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp172_AST_in = _t;
									match(_t,UTIMES);
									_t = _t->getFirstChild();
									ANTLR_USE_NAMESPACE(antlr)RefAST __t283 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp173_AST_in = _t;
									match(_t,INC);
									_t = _t->getFirstChild();
									out(_t);
									_t = _retTree;
									_t = __t283;
									_t = _t->getNextSibling();
									_t = __t282;
									_t = _t->getNextSibling();
									}
								}
								catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
									synPredMatched284 = false;
								}
								_t = __t284;
								inputState->guessing--;
							}
							if ( synPredMatched284 ) {
								ANTLR_USE_NAMESPACE(antlr)RefAST __t285 = _t;
								ANTLR_USE_NAMESPACE(antlr)RefAST tmp174_AST_in = _t;
								match(_t,UTIMES);
								_t = _t->getFirstChild();
								ANTLR_USE_NAMESPACE(antlr)RefAST __t286 = _t;
								ANTLR_USE_NAMESPACE(antlr)RefAST tmp175_AST_in = _t;
								match(_t,INC);
								_t = _t->getFirstChild();
								var1=out_asn(_t);
								_t = _retTree;
								_t = __t286;
								_t = _t->getNextSibling();
								_t = __t285;
								_t = _t->getNextSibling();
								if ( inputState->guessing==0 ) {
#line 1902 "ncoGrammer.g"
									
									var=ncap_var_var_inc(var1,NULL_CEWI,INC,true,prs_arg);      
									
#line 1882 "ncoTree.cpp"
								}
							}
							else {
								bool synPredMatched290 = false;
								if (((_t->getType() == UTIMES))) {
									ANTLR_USE_NAMESPACE(antlr)RefAST __t290 = _t;
									synPredMatched290 = true;
									inputState->guessing++;
									try {
										{
										ANTLR_USE_NAMESPACE(antlr)RefAST __t288 = _t;
										ANTLR_USE_NAMESPACE(antlr)RefAST tmp176_AST_in = _t;
										match(_t,UTIMES);
										_t = _t->getFirstChild();
										ANTLR_USE_NAMESPACE(antlr)RefAST __t289 = _t;
										ANTLR_USE_NAMESPACE(antlr)RefAST tmp177_AST_in = _t;
										match(_t,DEC);
										_t = _t->getFirstChild();
										out(_t);
										_t = _retTree;
										_t = __t289;
										_t = _t->getNextSibling();
										_t = __t288;
										_t = _t->getNextSibling();
										}
									}
									catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
										synPredMatched290 = false;
									}
									_t = __t290;
									inputState->guessing--;
								}
								if ( synPredMatched290 ) {
									ANTLR_USE_NAMESPACE(antlr)RefAST __t291 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp178_AST_in = _t;
									match(_t,UTIMES);
									_t = _t->getFirstChild();
									ANTLR_USE_NAMESPACE(antlr)RefAST __t292 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp179_AST_in = _t;
									match(_t,DEC);
									_t = _t->getFirstChild();
									var1=out_asn(_t);
									_t = _retTree;
									_t = __t292;
									_t = _t->getNextSibling();
									_t = __t291;
									_t = _t->getNextSibling();
									if ( inputState->guessing==0 ) {
#line 1905 "ncoGrammer.g"
										
										var=ncap_var_var_inc(var1,NULL_CEWI,DEC,true,prs_arg);      
										
#line 1935 "ncoTree.cpp"
									}
								}
								else if ((_t->getType() == MINUS)) {
									ANTLR_USE_NAMESPACE(antlr)RefAST __t298 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp180_AST_in = _t;
									match(_t,MINUS);
									_t = _t->getFirstChild();
									var1=out(_t);
									_t = _retTree;
									_t = __t298;
									_t = _t->getNextSibling();
									if ( inputState->guessing==0 ) {
#line 1923 "ncoGrammer.g"
										var=ncap_var_var_op(var1,NULL_CEWI, MINUS );
#line 1950 "ncoTree.cpp"
									}
								}
								else if ((_t->getType() == PLUS)) {
									ANTLR_USE_NAMESPACE(antlr)RefAST __t299 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp181_AST_in = _t;
									match(_t,PLUS);
									_t = _t->getFirstChild();
									var1=out(_t);
									_t = _retTree;
									_t = __t299;
									_t = _t->getNextSibling();
								}
								else {
									bool synPredMatched325 = false;
									if (((_t->getType() == VAR_ID))) {
										ANTLR_USE_NAMESPACE(antlr)RefAST __t325 = _t;
										synPredMatched325 = true;
										inputState->guessing++;
										try {
											{
											ANTLR_USE_NAMESPACE(antlr)RefAST __t324 = _t;
											ANTLR_USE_NAMESPACE(antlr)RefAST tmp182_AST_in = _t;
											match(_t,VAR_ID);
											_t = _t->getFirstChild();
											ANTLR_USE_NAMESPACE(antlr)RefAST tmp183_AST_in = _t;
											match(_t,LMT_LIST);
											_t = _t->getNextSibling();
											_t = __t324;
											_t = _t->getNextSibling();
											}
										}
										catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
											synPredMatched325 = false;
										}
										_t = __t325;
										inputState->guessing--;
									}
									if ( synPredMatched325 ) {
										ANTLR_USE_NAMESPACE(antlr)RefAST __t326 = _t;
										vid = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
										match(_t,VAR_ID);
										_t = _t->getFirstChild();
										ANTLR_USE_NAMESPACE(antlr)RefAST tmp184_AST_in = _t;
										match(_t,LMT_LIST);
										_t = _t->getNextSibling();
										_t = __t326;
										_t = _t->getNextSibling();
										if ( inputState->guessing==0 ) {
#line 2094 "ncoGrammer.g"
											
											var=var_lmt(vid);
											
											
#line 2004 "ncoTree.cpp"
										}
									}
									else if ((_t->getType() == VAR_ID)) {
										v = _t;
										match(_t,VAR_ID);
										_t = _t->getNextSibling();
										if ( inputState->guessing==0 ) {
#line 2101 "ncoGrammer.g"
											
											
											var=prs_arg->ncap_var_init(v->getText(),true);
											if(var== NULL){
											if(prs_arg->ntl_scn){
											var=ncap_var_udf(v->getText().c_str());
											return var;
											}else
											nco_exit(EXIT_FAILURE);
											}
											
											// apply cast only if sz >1 
											if(bcst && var->sz >1)
											var=ncap_cst_do(var,var_cst,prs_arg->ntl_scn);
											
											
											
#line 2030 "ncoTree.cpp"
										}
									}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}}}}}}}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::assign_ntl(ANTLR_USE_NAMESPACE(antlr)RefAST _t,
	bool bram
) {
#line 1325 "ncoGrammer.g"
	var_sct *var;
#line 2056 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST assign_ntl_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST dmn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 1325 "ncoGrammer.g"
	
	const std::string fnc_nm("assign_ntl"); 
	var=NULL_CEWI;
	
#line 2071 "ncoTree.cpp"
	
	try {      // for error handling
		bool synPredMatched229 = false;
		if (((_t->getType() == VAR_ID))) {
			ANTLR_USE_NAMESPACE(antlr)RefAST __t229 = _t;
			synPredMatched229 = true;
			inputState->guessing++;
			try {
				{
				ANTLR_USE_NAMESPACE(antlr)RefAST __t228 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp185_AST_in = _t;
				match(_t,VAR_ID);
				_t = _t->getFirstChild();
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp186_AST_in = _t;
				match(_t,LMT_LIST);
				_t = _t->getNextSibling();
				_t = __t228;
				_t = _t->getNextSibling();
				}
			}
			catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
				synPredMatched229 = false;
			}
			_t = __t229;
			inputState->guessing--;
		}
		if ( synPredMatched229 ) {
			ANTLR_USE_NAMESPACE(antlr)RefAST __t230 = _t;
			vid = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
			match(_t,VAR_ID);
			_t = _t->getFirstChild();
			lmt = _t;
			match(_t,LMT_LIST);
			_t = _t->getNextSibling();
			_t = __t230;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1330 "ncoGrammer.g"
				
				
				
				std::string var_nm; 
				var_sct *var_lhs;
				var_sct *var_rhs;
				NcapVar *Nvar;              
				
				var_nm=vid->getText();
				
				
				
				if(dbg_lvl_get() > 0)
				dbg_prn(fnc_nm,var_nm+"(limits)");
				
				// evaluate rhs for side effects eg new dims or lvalues 
				var_rhs=out(vid->getNextSibling());         
				var_rhs=nco_var_free(var_rhs);               
				
				
				var_lhs=prs_arg->ncap_var_init(var_nm,false);
				if(var_lhs){
				var=nco_var_dpl(var_lhs);
				(void)prs_arg->ncap_var_write(var_lhs,bram);
				} else {
				
				// set var to udf
				var_lhs=ncap_var_udf(var_nm.c_str());
				var=nco_var_dpl(var_lhs);
				
				Nvar=new NcapVar(var_lhs);
				(void)prs_arg->int_vtr.push_ow(Nvar);
				}
				
#line 2144 "ncoTree.cpp"
			}
		}
		else {
			bool synPredMatched233 = false;
			if (((_t->getType() == VAR_ID))) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t233 = _t;
				synPredMatched233 = true;
				inputState->guessing++;
				try {
					{
					ANTLR_USE_NAMESPACE(antlr)RefAST __t232 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp187_AST_in = _t;
					match(_t,VAR_ID);
					_t = _t->getFirstChild();
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp188_AST_in = _t;
					match(_t,DMN_LIST);
					_t = _t->getNextSibling();
					_t = __t232;
					_t = _t->getNextSibling();
					}
				}
				catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
					synPredMatched233 = false;
				}
				_t = __t233;
				inputState->guessing--;
			}
			if ( synPredMatched233 ) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t234 = _t;
				vid1 = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
				match(_t,VAR_ID);
				_t = _t->getFirstChild();
				dmn = _t;
				match(_t,DMN_LIST);
				_t = _t->getNextSibling();
				_t = __t234;
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1365 "ncoGrammer.g"
					
					
					int idx;
					std::string var_nm;
					var_sct *var1;
					std::vector<std::string> str_vtr;
					RefAST  aRef;
					NcapVar *Nvar;
					int str_vtr_sz;
					
					var_nm=vid1->getText();               
					
					if(dbg_lvl_get() > 0)
					dbg_prn(fnc_nm,var_nm+"[dims]");
					
					
					
					// set class wide variables
					bcst=true;  
					var_cst=NULL_CEWI;
					
					aRef=dmn->getFirstChild();
					
					// pPut dimension names in vector       
					while(aRef) {
					str_vtr.push_back(aRef->getText());
					aRef=aRef->getNextSibling();      
					}
					
					//Check that all dims exist
					str_vtr_sz=str_vtr.size();
					for(idx=0 ; idx < str_vtr_sz ; idx++)
					if(   prs_arg->dmn_in_vtr.findi(str_vtr[idx]) ==-1             
					&& prs_arg->dmn_out_vtr.findi(str_vtr[idx]) ==-1)      
					break;
					
					// return undef if dim missing 
					if( idx <str_vtr_sz){
					var=NULL_CEWI;
					
					} else {
					
					// Cast is applied in VAR_ID action in function out()
					var_cst=ncap_cst_mk(str_vtr,prs_arg);
					
					var1=out(vid1->getNextSibling());
					if(var1->undefined) {
					var=NULL_CEWI;
					} else {
					var_cst=nco_var_cnf_typ(var1->type,var_cst);
					var_cst->typ_dsk=var1->type;
					var=nco_var_dpl(var_cst);
					
					}
					var1=nco_var_free(var1);
					}
					
					
					if(!var){
					var1=ncap_var_udf(var_nm.c_str());
					Nvar=new NcapVar(var1);
					(void)prs_arg->int_vtr.push_ow(Nvar);
					var=nco_var_dpl(var1);
					} else{
					var->nm=(char*)nco_free(var->nm);
					var->nm=strdup(var_nm.c_str());
					var1=nco_var_dpl(var);
					prs_arg->ncap_var_write(var1,bram);
					}
					
					if(var_cst)
					var_cst=nco_var_free(var_cst);
					
					bcst=false;   
					
					
#line 2260 "ncoTree.cpp"
				}
			}
			else if ((_t->getType() == VAR_ID)) {
				vid2 = _t;
				match(_t,VAR_ID);
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1442 "ncoGrammer.g"
					
					
					std::string var_nm;
					
					var_nm=vid2->getText();
					
					
					if(dbg_lvl_get() > 0)
					dbg_prn(fnc_nm,var_nm);
					
					
					var_sct *var1;
					
					// Set class wide variables           
					bcst=false;
					var_cst=NULL_CEWI; 
					
					
					// get shape from RHS
					var1=out(vid2->getNextSibling());
					(void)nco_free(var1->nm);                
					var1->nm =strdup(var_nm.c_str());
					
					//Copy return variable
					var=nco_var_dpl(var1);
					
					// Write var to int_vtr
					// if var already in int_vtr or var_vtr then write call does nothing
					(void)prs_arg->ncap_var_write(var1,bram);
					//(void)ncap_var_write_omp(var1,bram,prs_arg);
					
					
#line 2301 "ncoTree.cpp"
				}
			}
			else {
				bool synPredMatched237 = false;
				if (((_t->getType() == ATT_ID))) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t237 = _t;
					synPredMatched237 = true;
					inputState->guessing++;
					try {
						{
						ANTLR_USE_NAMESPACE(antlr)RefAST __t236 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp189_AST_in = _t;
						match(_t,ATT_ID);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp190_AST_in = _t;
						match(_t,LMT_LIST);
						_t = _t->getNextSibling();
						_t = __t236;
						_t = _t->getNextSibling();
						}
					}
					catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
						synPredMatched237 = false;
					}
					_t = __t237;
					inputState->guessing--;
				}
				if ( synPredMatched237 ) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t238 = _t;
					att = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
					match(_t,ATT_ID);
					_t = _t->getFirstChild();
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp191_AST_in = _t;
					match(_t,LMT_LIST);
					_t = _t->getNextSibling();
					_t = __t238;
					_t = _t->getNextSibling();
					if ( inputState->guessing==0 ) {
#line 1475 "ncoGrammer.g"
						
						;
						
#line 2344 "ncoTree.cpp"
					}
				}
				else {
					bool synPredMatched241 = false;
					if (((_t->getType() == ATT_ID))) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t241 = _t;
						synPredMatched241 = true;
						inputState->guessing++;
						try {
							{
							ANTLR_USE_NAMESPACE(antlr)RefAST __t240 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp192_AST_in = _t;
							match(_t,ATT_ID);
							_t = _t->getFirstChild();
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp193_AST_in = _t;
							match(_t,LMT_DMN);
							_t = _t->getNextSibling();
							_t = __t240;
							_t = _t->getNextSibling();
							}
						}
						catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
							synPredMatched241 = false;
						}
						_t = __t241;
						inputState->guessing--;
					}
					if ( synPredMatched241 ) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t242 = _t;
						att1 = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
						match(_t,ATT_ID);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp194_AST_in = _t;
						match(_t,DMN_LIST);
						_t = _t->getNextSibling();
						_t = __t242;
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1478 "ncoGrammer.g"
							
							;
							
#line 2387 "ncoTree.cpp"
						}
					}
					else if ((_t->getType() == ATT_ID)) {
						att2 = _t;
						match(_t,ATT_ID);
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1481 "ncoGrammer.g"
							
							
							//In Initial scan all newly defined atts are flagged as Undefined
							var_sct *var1;
							NcapVar *Nvar;
							
							if(dbg_lvl_get() > 0)
							dbg_prn(fnc_nm,att2->getText());
							
							
							var1=ncap_var_udf(att2->getText().c_str());
							
							Nvar=new NcapVar(var1);
							prs_arg->int_vtr.push_ow(Nvar);          
							
							// Copy return variable
							var=nco_var_dpl(var1);    
							
							
#line 2415 "ncoTree.cpp"
						}
					}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}}}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::assign(ANTLR_USE_NAMESPACE(antlr)RefAST _t,
	bool bram
) {
#line 1504 "ncoGrammer.g"
	var_sct *var;
#line 2441 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST assign_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST dmn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 1504 "ncoGrammer.g"
	
	const std::string fnc_nm("assign"); 
	var=NULL_CEWI;
	
#line 2456 "ncoTree.cpp"
	
	try {      // for error handling
		bool synPredMatched246 = false;
		if (((_t->getType() == VAR_ID))) {
			ANTLR_USE_NAMESPACE(antlr)RefAST __t246 = _t;
			synPredMatched246 = true;
			inputState->guessing++;
			try {
				{
				ANTLR_USE_NAMESPACE(antlr)RefAST __t245 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp195_AST_in = _t;
				match(_t,VAR_ID);
				_t = _t->getFirstChild();
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp196_AST_in = _t;
				match(_t,LMT_LIST);
				_t = _t->getNextSibling();
				_t = __t245;
				_t = _t->getNextSibling();
				}
			}
			catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
				synPredMatched246 = false;
			}
			_t = __t246;
			inputState->guessing--;
		}
		if ( synPredMatched246 ) {
			ANTLR_USE_NAMESPACE(antlr)RefAST __t247 = _t;
			vid = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
			match(_t,VAR_ID);
			_t = _t->getFirstChild();
			lmt = _t;
			match(_t,LMT_LIST);
			_t = _t->getNextSibling();
			_t = __t247;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1510 "ncoGrammer.g"
				
				
				int idx;
				int nbr_dmn;
				int var_id; 
				int slb_sz;
				std::string var_nm;
				
				RefAST lmt_Ref;
				var_sct *var_lhs=NULL_CEWI;
				var_sct *var_rhs=NULL_CEWI;
				NcapVector<lmt_sct*> lmt_vtr;          
				
				lmt_Ref=vid->getFirstChild();
				
				bcst=false;
				var_cst=NULL_CEWI;
				var=NULL_CEWI;
				NcapVar *Nvar; 
				
				
				
				var_nm=vid->getText();
				
				if(dbg_lvl_get() > 0)
				dbg_prn(fnc_nm,var_nm+"(limits)");
				
				lmt_Ref=lmt;               
				
				Nvar=prs_arg->var_vtr.find(var_nm);
				
				// Overwrite bram possibly 
				if(Nvar) 
				bram=Nvar->flg_mem;
				
				
				// Deal with RAM variables
				if(bram) {
				
				
				if(Nvar && Nvar->flg_stt==1){
				var_sct *var_ini;
				var_ini=prs_arg->ncap_var_init(var_nm,true);       
				Nvar->var->val.vp=var_ini->val.vp;
				var_ini->val.vp=(void*)NULL;
				var_ini=nco_var_free(var_ini);
				Nvar->flg_stt=2; 
				}
				
				if(Nvar && Nvar->flg_stt==2)
				var_lhs=Nvar->var;    
				
				
				if(!Nvar)
				var_lhs=prs_arg->ncap_var_init(var_nm,true);       
				
				
				nbr_dmn=var_lhs->nbr_dim;
				
				// Now populate lmt_vtr;
				if( lmt_mk(lmt_Ref,lmt_vtr) == 0)
				err_prn(fnc_nm,"Invalid hyperslab limits for variable "+ var_nm);
				
				
				if( lmt_vtr.size() != nbr_dmn)
				err_prn(fnc_nm,"Number of hyperslab limits for variable "+ var_nm+" doesn't match number of dimensions");
				
				
				// add dim names to dimension list 
				for(idx=0 ; idx < nbr_dmn;idx++) 
				lmt_vtr[idx]->nm=strdup(var_lhs->dim[idx]->nm);   
				
				
				slb_sz=1;        
				// fill out limit structure
				for(idx=0 ; idx < nbr_dmn ;idx++){
				(void)ncap_lmt_evl(prs_arg->out_id,lmt_vtr[idx],prs_arg);
				// Calculate size
				slb_sz *= lmt_vtr[idx]->cnt;
				}
				// Calculate RHS variable                  
				var_rhs=out(vid->getNextSibling());         
				// Convert to LHS type
				var_rhs=nco_var_cnf_typ(var_lhs->type,var_rhs);             
				
				// deal with scalar on RHS first         
				if(var_rhs->sz == 1)
				(void)ncap_att_stretch(var_rhs,slb_sz);
				
				
				// make sure var_lhs and var_rhs are the same size
				// and that they are the same shape (ie they conform!!)          
				if(var_rhs->sz != slb_sz){
				err_prn(fnc_nm, "Hyperslab for "+var_nm+" - number of elements on LHS(" +nbr2sng(slb_sz) +  ") doesn't equal number of elements on RHS(" +nbr2sng(var_rhs->sz) +  ")");                                       
				}
				
				(void)nco_put_var_mem(var_rhs,var_lhs,lmt_vtr);
				if(Nvar==NULL)
				(void)prs_arg->ncap_var_write(var_lhs,true); 
				
				
				
				// deal with Regular Vars
				} else {                 
				
				
				// if var undefined in O or defined but not populated
				if(!Nvar || ( Nvar && Nvar->flg_stt==1)){              
				// if var isn't in ouptut then copy it there
				//rcd=nco_inq_varid_flg(prs_arg->out_id,var_nm,&var_id);
				var_lhs=prs_arg->ncap_var_init(var_nm,true);
				
				// copy atts to output
				(void)ncap_att_cpy(var_nm,var_nm,prs_arg);
				(void)prs_arg->ncap_var_write(var_lhs,false);
				}
				
				// Get "new" var_id   
				(void)nco_inq_varid(prs_arg->out_id,var_nm.c_str(),&var_id);
				
				var_lhs=prs_arg->ncap_var_init(var_nm,false);
				
				nbr_dmn=var_lhs->nbr_dim;
				
				// Now populate lmt_vtr;
				if( lmt_mk(lmt_Ref,lmt_vtr) == 0)
				err_prn(fnc_nm,"Invalid hyperslab limits for variable "+ var_nm);
				
				
				if( lmt_vtr.size() != nbr_dmn)
				err_prn(fnc_nm,"Number of hyperslab limits for variable "+ var_nm+" doesn't match number of dimensions");
				
				
				// add dim names to dimension list 
				for(idx=0 ; idx < nbr_dmn;idx++) 
				lmt_vtr[idx]->nm=strdup(var_lhs->dim[idx]->nm);   
				
				
				var_lhs->sz=1;        
				// fill out limit structure
				for(idx=0 ; idx < nbr_dmn ;idx++){
				(void)ncap_lmt_evl(prs_arg->out_id,lmt_vtr[idx],prs_arg);
				// Calculate size
				var_lhs->sz *= lmt_vtr[idx]->cnt;
				}
				// Calculate RHS variable                  
				var_rhs=out(vid->getNextSibling());         
				// Convert to LHS type
				var_rhs=nco_var_cnf_typ(var_lhs->type,var_rhs);             
				
				// deal with scalar on RHS first         
				if(var_rhs->sz == 1){
				// stretch variable to var_lhs->sz                 
				(void)ncap_att_stretch(var_rhs,var_lhs->sz);
				}
				
				// make sure var_lhs and var_rhs are the same size
				// and that they are the same shape (ie they conform!!)          
				if(var_rhs->sz != var_lhs->sz){
				err_prn(fnc_nm, "Hyperslab for "+var_nm+" - number of elements on LHS(" +nbr2sng(var_lhs->sz) +  ") doesn't equal number of elements on RHS(" +nbr2sng(var_rhs->sz) +  ")");                                       
				}
				
				//put block              
				{ 
				long mult_srd=1L;
				std::vector<long> dmn_srt_vtr;
				std::vector<long> dmn_cnt_vtr;
				std::vector<long> dmn_srd_vtr;
				
				for(idx=0;idx<nbr_dmn;idx++){
				dmn_srt_vtr.push_back(lmt_vtr[idx]->srt);
				dmn_cnt_vtr.push_back(lmt_vtr[idx]->cnt);
				dmn_srd_vtr.push_back(lmt_vtr[idx]->srd);  
				mult_srd*=lmt_vtr[idx]->srd;
				} /* end loop over idx */
				
				/* Check for stride */
				if(mult_srd == 1L)
					            (void)nco_put_vara(prs_arg->out_id,var_id,&dmn_srt_vtr[0],&dmn_cnt_vtr[0],var_rhs->val.vp,var_rhs->type);
				else
					            (void)nco_put_vars(prs_arg->out_id,var_id,&dmn_srt_vtr[0],&dmn_cnt_vtr[0],&dmn_srd_vtr[0],var_rhs->val.vp,var_rhs->type);
				
				} // end put block !!
				
				
				var_lhs=nco_var_free(var_lhs);
				
				} // end else
				
				
				var_rhs=nco_var_free(var_rhs);
				
				// See If we have to return something
				if(lmt->getNextSibling() && lmt->getNextSibling()->getType()==NORET)
				var=NULL_CEWI;
				else 
				var=prs_arg->ncap_var_init(var_nm,true);
				
				
				// Empty and free vector 
				for(idx=0 ; idx < nbr_dmn ; idx++)
				(void)nco_lmt_free(lmt_vtr[idx]);
				
				
#line 2699 "ncoTree.cpp"
			}
		}
		else {
			bool synPredMatched250 = false;
			if (((_t->getType() == VAR_ID))) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t250 = _t;
				synPredMatched250 = true;
				inputState->guessing++;
				try {
					{
					ANTLR_USE_NAMESPACE(antlr)RefAST __t249 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp197_AST_in = _t;
					match(_t,VAR_ID);
					_t = _t->getFirstChild();
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp198_AST_in = _t;
					match(_t,DMN_LIST);
					_t = _t->getNextSibling();
					_t = __t249;
					_t = _t->getNextSibling();
					}
				}
				catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
					synPredMatched250 = false;
				}
				_t = __t250;
				inputState->guessing--;
			}
			if ( synPredMatched250 ) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t251 = _t;
				vid1 = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
				match(_t,VAR_ID);
				_t = _t->getFirstChild();
				dmn = _t;
				match(_t,DMN_LIST);
				_t = _t->getNextSibling();
				_t = __t251;
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1717 "ncoGrammer.g"
					
					
					var_sct *var1;
					std::vector<std::string> str_vtr;
					RefAST  aRef;
					std::string var_nm;              
					
					var_nm=vid1->getText();
					
					if(dbg_lvl_get() > 0)
					dbg_prn(fnc_nm,var_nm+"[dims]");
					
					
					// set class wide variables
					bcst=true;  
					var_cst=NULL_CEWI;
					
					
					//aRef=vid->getFirstChild()->getFirstChild();
					aRef=dmn->getFirstChild();
					
					// pPut dimension names in vector       
					while(aRef) {
					str_vtr.push_back(aRef->getText());
					aRef=aRef->getNextSibling();      
					}
					
					// Cast is applied in VAR_ID action in function out()
					var_cst=ncap_cst_mk(str_vtr,prs_arg);     
					var1=out(vid1->getNextSibling());
					
					(void)nco_free(var_cst->val.vp);
					var_cst->val.vp=(void*)NULL;
					
					bool br1=(var_cst->sz >1 && var1->sz==1);
					bool br2=(var_cst->sz==var1->sz &&  ( ncap_var_is_att(var1) ||var1->has_dpl_dmn==-1 ));
					
					
					if( br1 || br2){
					var_sct *var_nw;
					void *vp_swp;
					
					var_nw=nco_var_dpl(var_cst);
					var_nw=nco_var_cnf_typ(var1->type,var_nw);
					if(br1)
					(void)ncap_att_stretch(var1,var_nw->sz);
					
					vp_swp=var_nw->val.vp;
					var_nw->val.vp=var1->val.vp;
					var1->val.vp=vp_swp;
					
					var1=nco_var_free(var1);
					var1=var_nw;
					}
					
					//blow out if vars not the same size      
					if(var1->sz != var_cst->sz) 
					err_prn(fnc_nm, "LHS cast for "+var_nm+" - cannot make RHS "+ std::string(var1->nm) + " conform.");               
					
					var1->nm=(char*)nco_free(var1->nm);
					
					var1->nm =strdup(var_nm.c_str());
					
					
					
					// See If we have to return something
					if(dmn->getNextSibling() && dmn->getNextSibling()->getType()==NORET)
					var=NULL_CEWI;
					else 
					var=nco_var_dpl(var1);     
					
					
					
					//call to nco_var_get() in ncap_var_init() uses this property
					var1->typ_dsk=var1->type;
					(void)prs_arg->ncap_var_write(var1,bram);
					
					bcst=false;
					var_cst=nco_var_free(var_cst); 
					
					
					
#line 2821 "ncoTree.cpp"
				}
			}
			else if ((_t->getType() == VAR_ID)) {
				vid2 = _t;
				match(_t,VAR_ID);
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1800 "ncoGrammer.g"
					
					// Set class wide variables
					var_sct *var1;
					NcapVar *Nvar;
					std::string var_nm;
					
					var_nm=vid2->getText();       
					
					if(dbg_lvl_get() > 0)
					dbg_prn(fnc_nm,var_nm);
					
					
					
					bcst=false;
					var_cst=NULL_CEWI; 
					
					
					var1=out(vid2->getNextSibling());
					
					// Save name 
					std::string s_var_rhs(var1->nm);
					(void)nco_free(var1->nm);                
					var1->nm =strdup(var_nm.c_str());
					
					// Do attribute propagation only if
					// var doesn't already exist or is defined but NOT
					// populated
					Nvar=prs_arg->var_vtr.find(vid2->getText());
					//rcd=nco_inq_varid_flg(prs_arg->out_id,var1->nm ,&var_id);
					
					
					if(!Nvar || Nvar && Nvar->flg_stt==1)
					(void)ncap_att_cpy(var_nm,s_var_rhs,prs_arg);
					
					
					
					// See If we have to return something
					if(vid2->getFirstChild() && vid2->getFirstChild()->getType()==NORET)
					var=NULL_CEWI;
					else 
					var=nco_var_dpl(var1);               ;
					
					
					// Write var to disk
					(void)prs_arg->ncap_var_write(var1,bram);
					//(void)ncap_var_write_omp(var1,bram,prs_arg);
					
					
					
#line 2879 "ncoTree.cpp"
				}
			}
			else {
				bool synPredMatched254 = false;
				if (((_t->getType() == ATT_ID))) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t254 = _t;
					synPredMatched254 = true;
					inputState->guessing++;
					try {
						{
						ANTLR_USE_NAMESPACE(antlr)RefAST __t253 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp199_AST_in = _t;
						match(_t,ATT_ID);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp200_AST_in = _t;
						match(_t,LMT_LIST);
						_t = _t->getNextSibling();
						_t = __t253;
						_t = _t->getNextSibling();
						}
					}
					catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
						synPredMatched254 = false;
					}
					_t = __t254;
					inputState->guessing--;
				}
				if ( synPredMatched254 ) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t255 = _t;
					att = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
					match(_t,ATT_ID);
					_t = _t->getFirstChild();
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp201_AST_in = _t;
					match(_t,LMT_LIST);
					_t = _t->getNextSibling();
					_t = __t255;
					_t = _t->getNextSibling();
					if ( inputState->guessing==0 ) {
#line 1850 "ncoGrammer.g"
						
						;
						
#line 2922 "ncoTree.cpp"
					}
				}
				else {
					bool synPredMatched258 = false;
					if (((_t->getType() == ATT_ID))) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t258 = _t;
						synPredMatched258 = true;
						inputState->guessing++;
						try {
							{
							ANTLR_USE_NAMESPACE(antlr)RefAST __t257 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp202_AST_in = _t;
							match(_t,ATT_ID);
							_t = _t->getFirstChild();
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp203_AST_in = _t;
							match(_t,LMT_DMN);
							_t = _t->getNextSibling();
							_t = __t257;
							_t = _t->getNextSibling();
							}
						}
						catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
							synPredMatched258 = false;
						}
						_t = __t258;
						inputState->guessing--;
					}
					if ( synPredMatched258 ) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t259 = _t;
						att1 = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
						match(_t,ATT_ID);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp204_AST_in = _t;
						match(_t,DMN_LIST);
						_t = _t->getNextSibling();
						_t = __t259;
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1853 "ncoGrammer.g"
							
							;
							
#line 2965 "ncoTree.cpp"
						}
					}
					else if ((_t->getType() == ATT_ID)) {
						att2 = _t;
						match(_t,ATT_ID);
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1856 "ncoGrammer.g"
							
							
							var_sct *var1;
							string sa=att2->getText();
							
							if(dbg_lvl_get() > 0)
							dbg_prn(fnc_nm,sa);
							
							var1=out(att2->getNextSibling());
							(void)nco_free(var1->nm);
							var1->nm=strdup(sa.c_str());
							
							//var_nw=nco_var_dpl(var);
							NcapVar *Nvar=new NcapVar(var1,sa);
							prs_arg->var_vtr.push_ow(Nvar);       
							
							
							// See If we have to return something
							if(att2->getFirstChild() && att2->getFirstChild()->getType()==NORET)
							var=NULL_CEWI;
							else 
							var=nco_var_dpl(var1);               ;
							
							
#line 2998 "ncoTree.cpp"
						}
					}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}}}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::out_asn(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 2217 "ncoGrammer.g"
	var_sct *var;
#line 3022 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST out_asn_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 2217 "ncoGrammer.g"
	
	const std::string fnc_nm("assign_asn");
	var=NULL_CEWI; 
	
#line 3032 "ncoTree.cpp"
	
	try {      // for error handling
		if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = ASTNULL;
		switch ( _t->getType()) {
		case UTIMES:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t328 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp205_AST_in = _t;
			match(_t,UTIMES);
			_t = _t->getFirstChild();
			vid1 = _t;
			match(_t,VAR_ID);
			_t = _t->getNextSibling();
			_t = __t328;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2224 "ncoGrammer.g"
				
				if(vid1->getFirstChild())
				err_prn(fnc_nm,"Invalid Lvalue " +vid1->getText() );
				
				var=prs_arg->ncap_var_init(vid1->getText(),true);
				if(var== NULL_CEWI){
				nco_exit(EXIT_FAILURE);
				}
				
				
#line 3061 "ncoTree.cpp"
			}
			break;
		}
		case VAR_ID:
		{
			vid = _t;
			match(_t,VAR_ID);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2235 "ncoGrammer.g"
				
				if(vid->getFirstChild())
				err_prn(fnc_nm,"Invalid Lvalue " +vid->getText() );
				
				var=prs_arg->ncap_var_init(vid->getText(),true);
				if(var== NULL_CEWI){
				nco_exit(EXIT_FAILURE);
				}
				
				
				
				
#line 3084 "ncoTree.cpp"
			}
			break;
		}
		case ATT_ID:
		{
			att = _t;
			match(_t,ATT_ID);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2248 "ncoGrammer.g"
				
				// check "output"
				NcapVar *Nvar=NULL;
				
				if(att->getFirstChild())
				err_prn(fnc_nm,"Invalid Lvalue " +att->getText() );
				
				
				if(prs_arg->ntl_scn)
				Nvar=prs_arg->int_vtr.find(att->getText());
				
				if(Nvar==NULL) 
				Nvar=prs_arg->var_vtr.find(att->getText());
				
				var=NULL_CEWI;    
				if(Nvar !=NULL)
				var=nco_var_dpl(Nvar->var);
				else    
				var=ncap_att_init(att->getText(),prs_arg);
				
				
				if(!prs_arg->ntl_scn && var==NULL_CEWI ){
				err_prn(fnc_nm,"Unable to locate attribute " +att->getText()+ " in input or output files.");
				}
				
				// if att not found return undefined
				if(prs_arg->ntl_scn && var==NULL_CEWI )
				var=ncap_var_udf(att->getText().c_str());
				
				
				if(prs_arg->ntl_scn && var->val.vp !=NULL)
				var->val.vp=(void*)nco_free(var->val.vp);
				
				
				
#line 3130 "ncoTree.cpp"
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::value_list(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 2286 "ncoGrammer.g"
	var_sct *var;
#line 3156 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST value_list_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vlst = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 2286 "ncoGrammer.g"
	
	const std::string fnc_nm("value_list");
	var=NULL_CEWI; 
	
#line 3164 "ncoTree.cpp"
	
	try {      // for error handling
		{
		vlst = _t;
		match(_t,VALUE_LIST);
		_t = _t->getNextSibling();
		}
		if ( inputState->guessing==0 ) {
#line 2291 "ncoGrammer.g"
			
			
			char *cp;
			int nbr_lst;
			int idx;
			int tsz;
			
			
			nc_type type=NC_NAT;
			var_sct *var_ret;                        
			RefAST rRef;
			//NcapVector<var_sct*> exp_vtr;
			std::vector<var_sct*> exp_vtr;
			
			rRef=vlst->getFirstChild();
			//rRef=vlst->getNextSibling();
			
			/*
			if(prs_arg->ntl_scn){
			var=ncap_var_udf("~zz@value_list");  
			return var;
			}   
			*/
			
			while(rRef){
			exp_vtr.push_back(out(rRef));   
			rRef=rRef->getNextSibling();
			}       
			nbr_lst=exp_vtr.size();
			
			// find highest type
			for(idx=0;idx <nbr_lst ;idx++)
			if(exp_vtr[idx]->type > type) type=exp_vtr[idx]->type;     
			
			
			// Inital Scan
			if(prs_arg->ntl_scn){
			
			//skip loop if highest type is double 
			if(type==NC_DOUBLE) idx=nbr_lst;
			
			for(idx=0 ; idx <nbr_lst ; idx++) 
			if(exp_vtr[idx]->undefined) break;
			
			// Exit if an element in the list is "undefined" 
			if(idx < nbr_lst){ 
			var_ret=ncap_var_udf("~zz@value_list");  
			goto end_val;  
			}
			
			var_ret=(var_sct *)nco_malloc(sizeof(var_sct));
			/* Set defaults */
			(void)var_dfl_set(var_ret); 
			
			/* Overwrite with attribute expression information */
			var_ret->nm=strdup("~zz@value_list");
			var_ret->nbr_dim=0;
			var_ret->sz=nbr_lst;
			var_ret->type=type;
			
			goto end_val;          
			
			} // end initial scan
			
			// convert every element in vector to highest type
			for(idx=0;idx <nbr_lst ;idx++)
			exp_vtr[idx]=nco_var_cnf_typ(type,exp_vtr[idx]);  
			
			var_ret=(var_sct *)nco_malloc(sizeof(var_sct));
			/* Set defaults */
			(void)var_dfl_set(var_ret); 
			
			/* Overwrite with attribute expression information */
			var_ret->nm=strdup("~zz@value_list");
			var_ret->nbr_dim=0;
			var_ret->sz=nbr_lst;
			var_ret->type=type;
			
			tsz=nco_typ_lng(type);
			var_ret->val.vp=(void*)nco_malloc(nbr_lst*tsz);
			
			for(idx=0;idx <nbr_lst ; idx++){
			cp=(char*)(var_ret->val.vp)+ (ptrdiff_t)(idx*tsz);
			memcpy(cp,exp_vtr[idx]->val.vp,tsz);
			}    
			
			// Free vector        
			end_val: for(idx=0 ; idx < nbr_lst ; idx++)
			(void)nco_var_free(exp_vtr[idx]);    
			
			var=var_ret;
			
			
#line 3267 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

bool  ncoTree::where_assign(ANTLR_USE_NAMESPACE(antlr)RefAST _t,
	var_sct *var_msk
) {
#line 2388 "ncoGrammer.g"
	bool bret;
#line 3288 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST where_assign_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 2388 "ncoGrammer.g"
	
	const std::string fnc_nm("where_assign");
	var_sct *var_rhs;
	
	
#line 3297 "ncoTree.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t332 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp206_AST_in = _t;
		match(_t,EXPR);
		_t = _t->getFirstChild();
		ANTLR_USE_NAMESPACE(antlr)RefAST __t333 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp207_AST_in = _t;
		match(_t,ASSIGN);
		_t = _t->getFirstChild();
		vid = _t;
		match(_t,VAR_ID);
		_t = _t->getNextSibling();
		var_rhs=out(_t);
		_t = _retTree;
		_t = __t333;
		_t = _t->getNextSibling();
		_t = __t332;
		_t = _t->getNextSibling();
		if ( inputState->guessing==0 ) {
#line 2394 "ncoGrammer.g"
			
			
			bool bfr=false;
			nco_bool DO_CONFORM;
			std::string var_nm=vid->getText();
			var_sct *var_lhs;
			var_sct *var_tmp=NULL_CEWI;
			NcapVar *Nvar;
			
			bret=false;
			
			var_lhs=prs_arg->ncap_var_init(var_nm,true);
			if(var_lhs==NULL_CEWI) 
			nco_exit(EXIT_FAILURE);
			
			var_rhs=nco_var_cnf_typ(var_lhs->type,var_rhs);         
			if(var_rhs->sz >1L && var_rhs->sz != var_lhs->sz) {
			std::ostringstream os;
			os<<"assign in where: size of expression on rhs doesn't match size of var on lhs";  
			err_prn(fnc_nm,os.str());         
			}
			
			
			// Make mask conform
			var_tmp=nco_var_cnf_dmn(var_lhs,var_msk,var_tmp,True,&DO_CONFORM);
			if(var_msk != var_tmp){
			//var_msk=nco_var_free(var_msk);
			bfr=true;
			var_msk=var_tmp;
			}
			
			if(DO_CONFORM==False) {
			std::ostringstream os;
			os<<"Cannot make variable:"<<var_lhs->nm <<" and where mask variable "<<var_msk->nm <<" conform. ";
			err_prn(fnc_nm,os.str()); 
			}
			
			
			char *cp_in;
			char *cp_out;
			short *sp;
			long idx;
			long jdx;
			long sz;
			size_t slb_sz;
			bool b_vp=false;
			char *mss_cp;
			
			
			sz=var_lhs->sz;
			slb_sz=nco_typ_lng(var_lhs->type);
			
			(void)cast_void_nctype(NC_SHORT,&var_msk->val);
			//Dereference 
			sp=var_msk->val.sp; 
			
			cp_out=( char*)(var_lhs->val.vp);
			cp_in=( char*)(var_rhs->val.vp);
			
			if(var_lhs->has_mss_val) {
			mss_cp=( char*)var_lhs->mss_val.vp;
			b_vp=true;
			} else if(var_rhs->has_mss_val){
			mss_cp=( char*)var_rhs->mss_val.vp;
			b_vp=true;                 
			}        
			// missing values    
			if(b_vp) {
			if(var_rhs->sz==1L){ 
			
			for(idx=0; idx<sz; idx++) {
			if(sp[idx] && memcmp(cp_out,mss_cp,slb_sz))
			(void)memcpy(cp_out,cp_in,slb_sz);       
			cp_out+=slb_sz;
			} 
			} else {  
			for(idx=0; idx<sz; idx++) {
			if(sp[idx]&& memcmp(cp_out,mss_cp,slb_sz) 
			&& memcmp(cp_in,mss_cp,slb_sz))
			(void)memcpy(cp_out,cp_in,slb_sz);      
			cp_out+=slb_sz;
			cp_in+=slb_sz;
			}
			} 
			// no missing values                
			} else { 
			
			if(var_rhs->sz==1L){ 
			
			for(idx=0; idx<sz; idx++) {
			if(sp[ idx])
			(void)memcpy(cp_out,cp_in,slb_sz);       
			cp_out+=slb_sz;
			} 
			} else {  
			for(idx=0; idx<sz; idx++) {
			if(sp[idx])
			(void)memcpy(cp_out,cp_in,slb_sz);      
			cp_out+=slb_sz;
			cp_in+=slb_sz;
			}
			} 
			}             
			
			
			
			(void)cast_nctype_void(NC_SHORT,&var_msk->val); 
			
			// free "local" copy of var_msk if necessary
			if(bfr)
			var_msk=nco_var_free(var_msk);           
			
			
			// Do attribute propagation if LHS is new
			Nvar=prs_arg->var_vtr.find(var_nm);
			if(!Nvar)
			(void)ncap_att_cpy(var_nm,std::string(var_rhs->nm),prs_arg);
			
			var_rhs=nco_var_free(var_rhs);
			
			prs_arg->ncap_var_write(var_lhs,false);
			bret=true;
			
			
#line 3443 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return bret;
}

var_sct * ncoTree::var_lmt(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 2522 "ncoGrammer.g"
	var_sct *var;
#line 3462 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST var_lmt_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 2522 "ncoGrammer.g"
	
	const std::string fnc_nm("var_lmt");
	var=NULL_CEWI; 
	
#line 3471 "ncoTree.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t335 = _t;
		vid = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
		match(_t,VAR_ID);
		_t = _t->getFirstChild();
		lmt = _t;
		match(_t,LMT_LIST);
		_t = _t->getNextSibling();
		_t = __t335;
		_t = _t->getNextSibling();
		if ( inputState->guessing==0 ) {
#line 2527 "ncoGrammer.g"
			
			bool bram;   // Check for a RAM variable
			bool bnrm;
			int idx;
			int nbr_dmn;
			std::string var_nm;
			var_sct *var_rhs;
			var_sct *var_nw=NULL_CEWI;
			var_sct *var1=NULL_CEWI;
			dmn_sct *dmn_nw;
			
			
			NcapVar *Nvar;
			RefAST lRef;           
			
			NcapVector<lmt_sct*> lmt_vtr;
			NcapVector<dmn_sct*> dmn_vtr;
			NcapVector<std::string> dmn_nrm_vtr;  // list of normalized vectors    
			
			
			var_nm=vid->getText(); 
			var_rhs=prs_arg->ncap_var_init(var_nm,false);            
			nbr_dmn=var_rhs->nbr_dim;          
			lRef=lmt;
			
			// Check for RAM variable
			Nvar=prs_arg->var_vtr.find(var_nm);
			if(Nvar && Nvar->flg_mem){ 
			bram=true;
			var_rhs=nco_var_free(var_rhs);
			
			var_rhs=Nvar->cpyVar();
			var_rhs->nc_id=prs_arg->out_id;
			}else{
			bram=false;
			}
			
			
			if(prs_arg->ntl_scn){
			// check limit only contain numbers or dim_id.size()
			std::vector<std::string> str_vtr;
			(void)ncap_mpi_get_id(lRef,str_vtr);
			if(str_vtr.size()>0){
			var=ncap_var_udf("~rhs_undefined");       
			goto end2;  // cannot use return var!!
			}
			// Temporarily change mode 
			prs_arg->ntl_scn=False;
			lmt_mk(lRef,lmt_vtr);
			prs_arg->ntl_scn=True; 
			
			}else{
			lmt_mk(lRef,lmt_vtr);
			}
			
			if( lmt_vtr.size() != nbr_dmn)
			err_prn(fnc_nm,"Number of hyperslab limits for variable "+ vid->getText()+" doesn't match number of dimensions");
			
			
			// add dim names to dimension list 
			for(idx=0 ; idx < nbr_dmn;idx++)
			lmt_vtr[idx]->nm=strdup(var_rhs->dim[idx]->nm);   
			
			// fill out limit structure
			for(idx=0 ; idx < nbr_dmn ;idx++)
			(void)ncap_lmt_evl(var_rhs->nc_id,lmt_vtr[idx],prs_arg);
			
			// See if var can be normalized
			for(idx=0; idx<nbr_dmn ; idx++){
			if(lmt_vtr[idx]->cnt==1) 
			continue;
			if(lmt_vtr[idx]->cnt != var_rhs->dim[idx]->cnt) 
			break;
			dmn_nrm_vtr.push_back(std::string(lmt_vtr[idx]->nm));
			} 
			bnrm= (idx==nbr_dmn ? true:false);       
			
			// Blow out 
			if(!bnrm && prs_arg->ntl_scn){ 
			var=ncap_var_udf("~rhs_undefined");       
			goto end1;
			}     
			// Create var with normalized dims
			if(bnrm){
			var=ncap_cst_mk(dmn_nrm_vtr,prs_arg);
			(void)nco_free(var->nm);
			if(var->val.vp)
			var->val.vp=nco_free(var->val.vp); 
			
			var->nm=strdup(var_nm.c_str());
			var=nco_var_cnf_typ(var_rhs->type,var);
			}
			
			if(bnrm && prs_arg->ntl_scn) {
			// apply LHS cast if necessary 
			if(var->sz >1 && bcst)
			var=ncap_cst_do(var,var_cst,prs_arg->ntl_scn);
			goto end1;
			}
			
			
			// copy lmt_sct to dmn_sct;
			for(idx=0 ;idx <nbr_dmn ; idx++){
			dmn_nw=(dmn_sct*)nco_malloc(sizeof(dmn_sct));
			dmn_nw->nm=strdup(lmt_vtr[idx]->nm);
			
			// Fudge -if the variable is from input then nco_lmt_evl
			// overwrites the dim id's with their input file values
			// we want the dim ids from output  
			dmn_nw->id=var_rhs->dim[idx]->id;
			//dmn_nw->id=lmt_vtr[idx]->id;
			dmn_nw->cnt=lmt_vtr[idx]->cnt;  
			dmn_nw->srt=lmt_vtr[idx]->srt;  
			dmn_nw->end=lmt_vtr[idx]->end;  
			dmn_nw->srd=lmt_vtr[idx]->srd;  
			dmn_vtr.push_back(dmn_nw);
			}
			
			if(!bram){
			// Fudge -- fill out var again -but using dims defined in dmn_vtr
			// We need data in var so that LHS logic in assign can access var shape 
			var_nw=nco_var_fll(var_rhs->nc_id,var_rhs->id,var_nm.c_str(), &dmn_vtr[0],dmn_vtr.size()); 
			
			// Now get data from disk - use nco_var_get() 
			(void)nco_var_get(var_nw->nc_id,var_nw); 
			}
			
			// Ram variable -do an in memory get  
			if(bram){
			
			//Do an in memory get 
			(void)nco_get_var_mem(var_rhs,dmn_vtr);
			var_nw=nco_var_dpl(var_rhs);
			}
			
			
			/* a hack - we set var->has_dpl_dmn=-1 so we know we are dealing with 
			a hyperslabed var and not a regular var  -- It shouldn't cause 
			any abberant behaviour!! */ 
			
			var_nw->has_dpl_dmn=-1;  
			
			//if variable is scalar -- re-organize in a  new var - loose extraneous material
			if(var_nw->sz ==1) {
			var1=(var_sct *)nco_malloc(sizeof(var_sct));
			/* Set defaults */
			(void)var_dfl_set(var1); 
			var1->nm=strdup(var_nw->nm);
			var1->nbr_dim=0;
			var1->sz=1;
			var1->type=var_nw->type;
			
			var1->val.vp=(void*)nco_malloc(nco_typ_lng(var1->type));
			(void)memcpy( (void*)var1->val.vp,var_nw->val.vp,nco_typ_lng(var1->type));
			var_nw=nco_var_free(var_nw);
			
			// free casting variable
			if(bnrm)
			var=nco_var_free(var);
			
			var=var1;
			
			
			}else{
			
			if(!bnrm)
			var=var_nw;
			else{
			// swap values about in var_nm & var (the var cast earlier)
			//(void)nco_free(var->val.vp);
			var->val.vp=var_nw->val.vp;
			var_nw->val.vp=(void*)NULL;       
			(void)nco_var_free(var_nw);    
			}
			
			}   
			
			/* Casting a hyperslab --this makes my brain  hurt!!! */
			if(bnrm && bcst && var->sz >1)
			var=ncap_cst_do(var,var_cst,prs_arg->ntl_scn);
			
			
			
			//free vectors
			end0: ;
			for(idx=0 ; idx < nbr_dmn ; idx++)
			(void)nco_dmn_free(dmn_vtr[idx]);
			
			end1: ;
			for(idx=0 ; idx < nbr_dmn ; idx++)
			(void)nco_lmt_free(lmt_vtr[idx]);
			
			
			end2: var_rhs=nco_var_free(var_rhs); 
			
			end3: ;
			
			
#line 3683 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

void ncoTree::initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& )
{
}
const char* ncoTree::tokenNames[] = {
	"<0>",
	"EOF",
	"<2>",
	"NULL_TREE_LOOKAHEAD",
	"NULL_NODE",
	"BLOCK",
	"ARG_LIST",
	"DMN_LIST",
	"DMN_ARG_LIST",
	"LMT_LIST",
	"VALUE_LIST",
	"FUNC_ARG",
	"LMT",
	"EXPR",
	"FEXPR",
	"POST_INC",
	"POST_DEC",
	"UTIMES",
	"SQR2",
	"PROP",
	"FOR2",
	"NORET",
	"ATAN2",
	"GAMMA_INC",
	"WHERE_ASSIGN",
	"MISS2ZERO",
	";",
	"\"defdim\"",
	"(",
	"a string",
	",",
	")",
	"\"while\"",
	"\"break\"",
	"\"continue\"",
	"\"if\"",
	"\"else\"",
	"\"where\"",
	"\"elsewhere\"",
	"\"print\"",
	"VAR_ID",
	"ATT_ID",
	"{",
	"}",
	"\"for\"",
	":",
	"[",
	"DIM_ID",
	"]",
	"/",
	"dimension identifier",
	"dot operator",
	"FUNC",
	"++",
	"--",
	"!",
	"+",
	"-",
	"*",
	"power of operator",
	"%",
	"<<",
	">>",
	"<",
	">",
	">=",
	"<=",
	"==",
	"!=",
	"&&",
	"||",
	"?",
	"=",
	"+=",
	"-=",
	"*=",
	"/=",
	"FLOAT",
	"DOUBLE",
	"INT",
	"BYTE",
	"UBYTE",
	"SHORT",
	"USHORT",
	"UINT",
	"INT64",
	"UINT64",
	"DIM_ID_SIZE",
	"NRootAST",
	"\"<<\"",
	"\">>\"",
	"\\\"",
	"DGT",
	"LPH",
	"LPHDGT",
	"XPN",
	"VAR_NM",
	"VAR_NM_QT",
	"BLASTOUT",
	"UNUSED_OPS",
	"white space",
	"a C++-style comment",
	"a C-style comment",
	"a floating point number",
	"NUMBER",
	"variable or attribute identifier",
	"dimension identifier",
	"INCLUDE",
	"LMT_DMN",
	0
};



