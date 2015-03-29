type tree=record data,L,r:longint;end;
var
 t:array[0..400] of tree;
 opt:array[0..400,0..400] of longint;
 f:array[0..400] of longint;
 n,m,i,x,y:longint;
function max(x,y:longint):longint;
begin
 max:=x;
 if x<y then exit(y);
end;
function Dp(i,j:longint):longint;
var k:longint;
begin
 if opt[i,j]<0 then
  begin
   if (t[i].L<0)and(t[i].r<0)
    then
     begin
      if j<>1 then opt[i,j]:=0 else opt[i,j]:=t[i].data;
     end
    else
     if (t[i].L>=0)and(t[i].r<0) then opt[i,j]:=max(opt[i,j],Dp(t[i].L,j-1)+t[i].data)
      else if (t[i].L<0)and(t[i].r>=0) then
       begin
        opt[i,j]:=max(opt[i,j],Dp(t[i].r,j));
        opt[i,j]:=max(opt[i,j],Dp(t[i].r,j-1)+t[i].data);
       end
        else
         begin
          opt[i,j]:=max(opt[i,j],Dp(t[i].r,j));
          for k:=1 to j do
           opt[i,j]:=max(opt[i,j],Dp(t[i].L,k-1)+Dp(t[i].r,j-k)+t[i].data);
         end;
  end;
 exit(opt[i,j]);
end;
begin
 read(n,m);
 fillchar(f,sizeof(f),0);
 for i:=0 to n do
  begin
   t[i].L:=-1;
   t[i].r:=-1;
  end;
 for i:=1 to n do
  begin
   read(x,y);
   t[i].data:=y;
   if f[x]=0 then t[x].L:=i else t[f[x]].r:=i;
   f[x]:=i;
  end;
 fillchar(opt,sizeof(opt),200);
 for i:=0 to n do
  opt[i,0]:=0;
 writeln(Dp(0,m+1));
end.