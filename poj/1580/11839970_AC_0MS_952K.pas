var
  s,t:ansistring;
  n,i,j,k,ans,x,y:longint;
function gcd(x,y:longint):longint;
begin
  if y=0 then exit(x);
  exit(gcd(y,x mod y));
end;
begin
  while true do
    begin
      readln(s);
      if s='-1' then break;
      t:=copy(s,1,pos(' ',s)-1);
      delete(s,1,pos(' ',s));
      while s[1]=' ' do delete(s,1,1);
      ans:=0;
      for i:=1-length(t) to length(s)-1 do
        begin
          x:=0;
          for j:=1 to length(t) do
            if (1<=i+j)and(i+j<=length(s))and(s[i+j]=t[j]) then inc(x);
          if ans<x then ans:=x;
        end;
      ans:=ans*2;
      x:=length(s)+length(t);
      write('appx(',t,',',s,') = ');
      if ans=0 then
        begin
          writeln(0);
          continue;
        end;
      if ans=x then
        begin
          writeln(1);
          continue;
        end;
      y:=gcd(ans,x);
      writeln(ans div y,'/',x div y);
    end;
end.