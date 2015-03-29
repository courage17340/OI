var
  a:array[1..70] of string;
  v:array[1..70] of boolean;
  n,m,i,j,w,d:longint;
  s:string;
function next(x:longint):longint;
begin
  next:=x+1;
  if next>n then next:=1;
end;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  fillchar(v,sizeof(v),true);
  readln(s);
  val(copy(s,1,pos(',',s)-1),w);
  delete(s,1,pos(',',s));
  val(s,d);
  for i:=1 to n do
    begin
      for j:=1 to d-1 do
        begin
          while not v[w] do w:=next(w);
          w:=next(w);
        end;
      while not v[w] do w:=next(w);
      writeln(a[w]);
      v[w]:=false;
      w:=next(w);
    end;
end.