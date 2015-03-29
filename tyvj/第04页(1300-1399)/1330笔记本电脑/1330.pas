var
  n,x,y,i,j,k:longint;
  s:int64;
begin
  read(n);
  x:=n;y:=1;
  for i:=2 to trunc(sqrt(n)) do
    if n mod i=0 then begin k:=0;while n mod i=0 do begin n:=n div i;k:=1-k;end;if k=1 then y:=y*i;end;
  if n>1 then y:=y*n;
  if y=1 then  s:=int64((trunc(sqrt(x))+1))*int64((trunc(sqrt(x))+1)) else
  s:=int64(int64(x)+int64(y)+int64(2*trunc(sqrt(x)*sqrt(y))));
  if x=y then begin s:=int64(int64(x)+int64(x));s:=int64(int64(s)+int64(s));end;
  writeln(s);
end.
