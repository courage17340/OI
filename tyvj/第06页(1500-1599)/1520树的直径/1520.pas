type
  point=^node;
  node=record
		 pre,next:point;
		 x,c:longint;
	   end;
var
  a:array[1..10000] of point;
  v:array[1..10000] of boolean;
  p:point;
  n,i,j,k,z,x,y,max:longint;
procedure search(k,l:longint);
begin
  v[k]:=true;
  if max<l then
    begin
	  max:=l;
	  z:=k;
	end;
  while a[k]^.pre<>nil do a[k]:=a[k]^.pre;
  while a[k]^.next<>nil do
    begin
	  a[k]:=a[k]^.next;
	  if not v[a[k]^.x] then search(a[k]^.x,l+a[k]^.c)
	end;
end;
begin
  readln(n);
  for i:=1 to n do
    begin
	  new(a[i]);
	  a[i]^.pre:=nil;
	  a[i]^.next:=nil;
	end;
  for i:=1 to n-1 do
    begin
	  readln(x,y,z);
	  new(p);
	  p^.pre:=a[x];
	  a[x]^.next:=p;
	  p^.next:=nil;
	  p^.x:=y;
	  p^.c:=z;
	  a[x]:=p;
	  new(p);
	  p^.pre:=a[y];
	  a[y]^.next:=p;
	  p^.next:=nil;
	  p^.x:=x;
	  p^.c:=z;
	  a[y]:=p;
	end;
  z:=0;
  max:=0;
  fillchar(v,sizeof(v),0);
  v[1]:=true;
  search(1,0);
  fillchar(v,sizeof(v),0);
  max:=0;
  v[z]:=true;
  search(z,0);
  writeln(max);
  readln;
end.