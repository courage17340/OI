var
  s:string;
  x,ans,i,j:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
procedure work;
begin
  delete(s,1,pos(' ',s));
  while s[1]=' ' do delete(s,1,1);
  delete(s,1,pos(' ',s));
  while s[1]=' ' do delete(s,1,1);
  val(copy(s,1,pos(' ',s)-1),x);
  if s[length(s)]='F' then inc(ans,x*2);
  if s[length(s)]='Y' then inc(ans,max(x,500));
  if s[length(s)]='B' then inc(ans,x*2-x shr 1); 
end;
begin
  while true do
    begin
      readln(s);
      if s='#' then break;
      ans:=0;
      work;
      while true do
        begin
          readln(s);
          if s='0' then break;
          work;
        end;
      writeln(ans);
    end;
end.